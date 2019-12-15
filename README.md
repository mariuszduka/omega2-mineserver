# Minecraft server for Omega2 with OLED Expansion support

Mineserver version: **0.2.0**

[Mineserver ](https://github.com/fador/mineserver) is a custom Minecraft server software written in C++ *by Fador & Nredor and others*.

**NOTICE:** 
Server still lacks features compared to original minecraft server.  
Working with **1.8.9** client (protocol 47)

Please note that the Omega2 minicomputer has got limited hardware resources that may affect the proper operation of the Minecraft server. The main purpose of making this package is to show that the Omega2 minicomputer can be used for numerous interesting applications that can prove to be extremely inspiring.  
Simply put, a Minecraft game played on Omega2 is always great entertainment!

## About Mineserver

**Mineserver** is completely open-sourced and licensed under a permissive 3 clause BSD Licence, meaning that you are free to use it whenever you like and for whatever you like!

## Features

 * Plugins (**omega2**, chatcommands, filelog, nether, passivemobs, etc..)
 * NBT parsing/saving
 * Lightmap generation
 * Config file
 * Normal mining/item spawning/item pickups
 * Basic physics for gravel and sand
 * Physics for water (currently revising this)
 * Flatland and terrain map generation (also biomegen!)
 * Working chests, furnaces & signs
 * User validation from minecraft.net
 * Protocol Encryption

## Requirements

The package requires a minimum of 40 MB flash memory storage.   
See instructions: [Booting from External Storage](https://docs.onion.io/omega2-docs/boot-from-external-storage.html)

Optional: [OLED Expansion](https://onion.io/store/oled-expansion/)

## Installation

Download the repo:
```
git clone https://github.com/mariuszduka/omega2-mineserver.git
```

and install package:
```
opkg install omega2-mineserver/mipsel_24kc/mineserver_0.2.0_mipsel_24kc.ipk
```

The package will be installed in the directory `/usr/bin/mineserver`.

Done!

## Configuration

The config file (`config.cfg`) sets three path names and one file name which are relevant to the server; with their example values they are:
```
system.path.data    = ".";
system.path.plugins = "plugins";
system.path.home    = ".";
system.pid_file     = "mineserver.pid";
```

Map generator setting:
```
map.storage.nbt.directories += ("data/Omega2":3);
```

## OLED Expansion plugin support

Set values in the config file (`config.cfg`):
```
omega2.oled.enable = true;
system.plugins += ("omega2");
```

The current number of players will be shown on the display.

## Usage

In the console, execute the command:
```
cd /usr/bin/mineserver
./mineserver
```

## Omega2 plugin for Mineserver

In the `plugins\omegs2` directory is the source code of the OLED Expansion support.  


## Known issues

The server may crash after some time.  
This is probably due to Omega2's technical capabilities.

## Resources

 * [Mineserver official homepage](https://mineserver.be/)
 * [Mineserver Plugin API](https://mineserver.be/wiki/Plugin_API)
 * [Mineserver on Github](https://github.com/fador/mineserver)
 * [Driver to program I2C based Onion Expansions](https://github.com/OnionIoT/i2c-exp-driver)

## License

MIT License

Copyright (c) 2019 Mariusz Duka

Permission is hereby granted, free of charge, to any person obtaining a copy
of this software and associated documentation files (the "Software"), to deal
in the Software without restriction, including without limitation the rights
to use, copy, modify, merge, publish, distribute, sublicense, and/or sell
copies of the Software, and to permit persons to whom the Software is
furnished to do so, subject to the following conditions:

The above copyright notice and this permission notice shall be included in all
copies or substantial portions of the Software.

THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE
AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER
LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM,
OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN THE
SOFTWARE.
