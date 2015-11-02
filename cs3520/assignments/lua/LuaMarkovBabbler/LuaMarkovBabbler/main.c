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

#include "lua.h"
#include "lualib.h"
#include "lauxlib.h"

void callLuaFunction(lua_State *L) {
    // access the function (pushes function on the stack)
    lua_getglobal(L, "square");

    // push parameter on to the stack
    lua_pushnumber(L, 3);

    // call the function (places result on top of stack)
    // 1 is the number of arguments and 1 is the number of return values
    lua_pcall(L, 1, 1, 0);

    // get result
    int result = lua_tonumber(L, -1);

    printf("result = %d\n", result); // should be 9 (3 squared)
}

// functions called by lua must return the number of values returned/pushed
int square(lua_State *L) {
    int x = lua_tonumber(L, 1);
    lua_pushinteger(L, x*x);

    return 1;
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

int main(int argc, const char * argv[]) {
    // input file
    if (argc < 3) {
        printf("Usage: %s <filename> <words count> <n (optional)>", argv[0]);
    }
    char *contents = readfile(argv[1]);
    printf("input file: %s\n", argv[1]);
    printf("contents = %s", contents);

    // number of words
    int numWords;
    numWords = atoi(argv[2]);
    printf("number of words: %i\n", numWords);

    // n-grams
    int n = 3;
    if (argc > 3) {
        n = atoi(argv[3]);
    }
    printf("n-grams: %d\n", n);

    // setup
    lua_State *L = luaL_newstate();
    luaL_openlibs(L);

    // register c function
    lua_register(L, "csquare", square);

    // load lua file
    luaL_dofile(L, "/Users/nate/school/cs3520/assignments/lua/LuaMarkovBabbler/LuaMarkovBabbler/test.lua");

    // call a lua function
    callLuaFunction(L);

    // shut down
    lua_close(L);
    return 0;
}
