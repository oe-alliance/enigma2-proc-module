enigma2-proc-module [![License: GPL v3](https://img.shields.io/badge/License-GPLv3-blue.svg)](https://www.gnu.org/licenses/gpl-3.0)
=================
enigma2-proc-module allows access to branding type variables through the proc file system. 
This is a kernel module so it is running before enigma starts. The variables are available 
from the command line as soon as linux is running. Unlike the branding module (which was 
designed as a Python only module) the variables are easily accessible from c++ code just 
by using `std::ifstream in(filename);` or similar code.

enigma2-proc-module also allows access to its variables through `modinfo -d`. This gives 
access to the module variables even if the module is not currently running, i.e. in another 
slot (e.g multiboot). An example python file has been provided that parses the output returned 
by `modinfo`.

Current labels:
---------------
These labels have been selected as they will be familiar to all OE-Alliance developers. If/when 
there is ever agreement of labels between OE-Alliance and image developers outside OE-Alliance 
those labels can also be added. A helper file has been included for quickly producing the code 
required to add extra labels. Below is a list of the current labels at this time.

`/proc/getBrandOEM`, e.g. `vuplus`

`/proc/getImageBuild`, e.g. `008`

`/proc/getLastBuildDate`, e.g. `20210302215706`

`/proc/getImageArch`, e.g. `cortexa15hf-neon-vfpv4`

`/proc/getImageDevBuild`, e.g. `009`

`/proc/getDisplayType`, e.g. `colorlcd800`

`/proc/getFeedsUrl`, e.g. `http://images.satellites-xml.org/feeds/openvix/experimental/5.4/vuultimo4k`

`/proc/getImageDistro`, e.g. `openvix`

`/proc/getImageType`, e.g. `experimental`

`/proc/getHaveAVJACK`, e.g. `False`

`/proc/getHaveCI`, e.g. `True`

`/proc/getHaveDVI`, e.g. `False`

`/proc/getHaveHDMI`, e.g. `True`

`/proc/getHaveHDMIinFHD`, e.g. `True`

`/proc/getHaveHDMIinHD`, e.g. `False`

`/proc/getHaveMiniTV`, e.g. `False`

`/proc/getHaveRCA`, e.g. `False`

`/proc/getHaveSCART`, e.g. `False`

`/proc/getHaveSCARTYUV`, e.g. `False`

`/proc/getHaveWOL`, e.g. `False`

`/proc/getHaveWWOL`, e.g. `False`

`/proc/getHaveYUV`, e.g. `False`

`/proc/getImageFolder`, e.g. `vuplus/ultimo4k`

`/proc/getImageFileSystem`, e.g. `tar.bz2 `

`/proc/getImageName`, e.g. `openvix-5.4.008.009.experimental-vuultimo4k`

`/proc/getImageVersion`, e.g. `5.4`

`/proc/getMachineKernelFile`, e.g. `kernel_auto.bin`

`/proc/getModel`, e.g. `vuultimo4k`

`/proc/getBoxType`, e.g. `vuultimo4k`

`/proc/getMachineBuild`, e.g. `vuultimo4k`

`/proc/getMachineBrand`, e.g. `Vu+`

`/proc/getMachineName`, e.g. `Ultimo4K`

`/proc/getMachineMKUBIFS`, e.g. `-m 2048 -e 126976 -c  `

`/proc/getMachineMtdKernel`, e.g. `mmcblk0p1`

`/proc/getMachineMtdRoot`, e.g. `mmcblk0p4`

`/proc/getMachineRootFile`, e.g. `rootfs.tar.bz2`

`/proc/getSocFamily`, e.g. `bcm7376`

`/proc/getHaveTranscoding1`, e.g. `transcoding`

`/proc/getMachineUBINIZE`, e.g. `-m 2048 -p 128KiB`

Attribution:
------------
Contains original, open source, material derived from Duckbox-Developers' e2_proc module:
https://github.com/Duckbox-Developers/driver/blob/master/e2_proc/e2_proc_main.c

Contains open source, material from OpenVision developers.
