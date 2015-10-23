#Giant Bomb API Reader
C++ is hard. It's been a long time since I've used it.

So I thought I would try to brush up on my skills with something that high level languages make trival: interacting with a web API.

to use:
```
$ gb_api YOUR_API_KEY_HERE
```
It should print out the latest 100 videos and their URLs.

This requires rapidjson. I don't know how you're supposed to handle requirements in c++ yet. So here's a link to it: https://github.com/miloyip/rapidjson

And libcurl. sudo apt-get libcurl-devl or whatever.

You'll want to fix the build script to not my home directory.

Also check out this cool picture of my cat: C:\My Documents\Justin\Cat Pictures\Cute Picture.jpeg
