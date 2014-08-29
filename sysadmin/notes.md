# SysAdmin Notes
## Wed Aug 27
**Users and Groups:** Why do we need them?
* permissions
  - easier
* security
  - Authentication _(Who are you?)_ - user login/password
  - Authorization _(What can you do?)_ - previleges

### /etc/passwd
By default there are users for different processes (you can't login to
those accounts).

There might be a user at the very bottom. Looks something like:
<pre>joe:x:1002:1002:Joe,,,:/home.local/joe:/bin/bash</pre>

* This first `x` is a placeholder for the password.
* The first `1002` is the _UID_ or User ID: files and folder map back to a
  particular UID.
* Next `1002` is the _GID_ or Group ID: this is the primary group ID
  because it is the first group this user is a member of.
* `Joe,,,` will consist of a bunch of info about the user aka `GECOS`:
  wiki it, dawg. Basically full name, building number, contact info,
etc.
* `/home.local/joe` is the home directory.
* `/bin/bash` is our shell.
  - remember bash is the _born again shell_.
  - shell is the command line interface
  - notice some users have `/bin/false` as their shell.

### etc/group
As the system was installed there were a bunch of groups for each user
in the `etc/passwd` file. The only one that we care about would be the
last one or any others we create.

<pre>joe:x:1002:</pre>

Comma separated list of users would appear at the end of that line for
all the users in the group. Besides that, refer to the notes about
`/etc/passwd`.

### /etc/shadow
Here you can see your encrypted password.

### File permissions

```shell
touch foo.txt
ls -n # directory listing
```
Output:
<pre>-rw-rw-r-- 4 1002 1002 joe joe 4096 Aug 26...</pre>

* first 3 refer to user permissions
* next 3 refer to group
* last 3 refer to global or _everyone else_
* ugo = 664
  - r: 4
  - w: 2
  - x: 1

### Add users
```shell
sudo adduser fred
```
Creates user 'fred', adds him to group 'fred' and creates a home
directory for him. Should prompt for a password then ask for GECOS info.

Confirm that the new user was created by doing viewing bottom of `/etc/passwd`.
Confirm the groups have been created by viewing `/etc/group`.

### Groups
Create a group `cit` and adds barney to that group
```shell
addgroup cit
addgroup barney cit
```

Add bar.txt to the web group
```shell
chgrp web bar.txt
```

Use `chown` to change the file owner and group.
```shell
chown joe:cs foo.txt
```

### Other Commands
* `chfn` changes the GECOS
* `chsh` change shell
* `groups` print the groups the user is in
* `who` who is logged in at the moment
* `finger` give info about user _if finger is installed_
* `chmod 666 bar.txt` change permissions of bar.txt to 666

## Wed Aug 29

### Announcements:
* Homework due dates should get pushed back because of technical
  difficulties.
* Don't worry if you don't have anything done yet.

### Review
4 = r = read      => you can `ls`
2 = w = write     => you can `touch`
1 = x = execute   => you can `cd` (in the case of a directory)
therefore,
5 = read and execute

If you can _write_ to a directory then that means you can modify its
contents which includes deleting, renaming, and adding
files/directories.

Process of executing a command:
1. Check UID. if that fails,
2. Check GID. if that fails,
3. Check world permissions

### Specialty bits (3)

3 special bits are:
* 4 = setuid bit = s
* 2 = setgid bit = s
* 1 = sticky bit = t

specialty/user/group/other
2750 = rwx r-s ---
6755 = rws r-s r-x
1777 = rwx rwx rwt
0644 = rw- r-- r--

rws r-S r-- = 6744 => remember `S` means that it is empty.

### Default Permissions
Files: `0666`
Directories: `0777`

Problems with this?
* Way too lax

#### uMASK
Each process has a mask that defines permission bits that should be
removed from newly created files and directories.

Typical settings include:
0002 = 644 => removes world permissions
0027 = ? => TODO!

The uMASK is inherited from parent process unless overridden.

