//
//  main.c
//  LuaMarkovBabbler
//
//  Created by Nate Armstrong on 11/1/15.
//  Copyright © 2015 Nate Armstrong. All rights reserved.
//

#include <stdio.h>
#include <stdlib.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <unistd.h>
#include <fcntl.h>
#include <ctype.h>
#include <string.h>

#include "lua.h"
#include "lualib.h"
#include "lauxlib.h"

void start(lua_State *L, const char *file, int words, int n) {
    lua_getglobal(L, "start");

    // push parameter on to the stack
    lua_pushstring(L, file);
    lua_pushnumber(L, words);
    lua_pushnumber(L, n);

    lua_pcall(L, 3, 0, 0);
}

char * readfile(const char *filename)
{
    struct stat info;
    int status = stat(filename, &info);
    if (status < 0)
    {
        perror("stat error");
        exit(1);
    }

    // get a buffer of the appropriate size
    int size = (int) info.st_size;
    char *buffer = malloc(size + 1); // + 1 for null character at end to mark end of string
    if (buffer == NULL)
    {
        perror("malloc error");
        exit(1);
    }

    // open the file
    int file_descriptor = open(filename, O_RDONLY);
    if (file_descriptor < 0)
    {
        perror("open error");
        exit(1);
    }

    // read the entire file
    char *ptr = buffer;
    int left = size;
    while (left > 0)
    {
        int chunk = (int)read(file_descriptor, ptr, left);
        if (chunk < 0)
        {
            perror("read error");
            exit(1);
        }
        else if (chunk == 0)
        {
            fprintf(stderr, "ran out of data\n");
            exit(1);
        }
        left -= chunk;
        ptr += chunk;
    }

    // terminate the string with a null
    *ptr = 0;

    // close the file
    status = close(file_descriptor);
    if (status < 0)
    {
        perror("close error");
        exit(1);
    }

    return buffer;
}

int l_loadFile(lua_State *L) {
    const char *file = lua_tostring(L, 1);
    char *contents = readfile(file);
    lua_pushstring(L, contents);
    return 1;
}

int l_getToken(lua_State *L) {
    const char *contents = lua_tostring(L, 1);
    int offset = lua_tonumber(L, 2);

    int first = offset;

    for (int i=first; contents[i] != '\0' && isspace(contents[i]); i++) {
        first = first + 1;
    }

    int end = first;

    for (int i=end; contents[i] != '\0' && !isspace(contents[i]); i++) {
        end = end + 1;
    }

    int len = end - first;
    char *raw;
    strncpy(raw, contents+first, len);

    char token[len+1];
    token[len] = '\0';
    for (int i=0; raw[i] != '\0'; i++) {
        if (isalnum(raw[i])) {
            token[i] = tolower(raw[i]);
        }
    }

    lua_pushstring(L, token);
    lua_pushnumber(L, end);

    return 2;
}

int main(int argc, const char * argv[]) {
    // input file
    if (argc < 3) {
        printf("Usage: %s <filename> <words count> <n (optional)>", argv[0]);
    }
    char *contents = readfile(argv[1]);
    printf("input file: %s\n", argv[1]);
    printf("contents = %s", contents);

    printf("curr dir %s\n", getcwd(NULL, 0));

    // number of words
    int words;
    words = atoi(argv[2]);
    printf("number of words: %i\n", words);

    // n-grams
    int n = 3;
    if (argc > 3) {
        n = atoi(argv[3]);
    }
    printf("n-grams: %d\n", n);

    // setup
    lua_State *L = luaL_newstate();
    luaL_openlibs(L);

    // register c functions
    lua_register(L, "load_file", l_loadFile);
    lua_register(L, "get_token", l_getToken);

    // load lua file
    luaL_dofile(L, "babbler.lua");

    start(L, argv[1], words, n);

    // shut down
    lua_close(L);
    return 0;
}
