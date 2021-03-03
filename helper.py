# This file is for adding new variables. Add them below and
# run this file. It will create the code required to be added
# to the various files. Output in "/tmp/helper-output".


outfile = "/tmp/helper-output"

env_vars = [
	# env_var, file name, folder name
#	("BRAND_OEM", "brandoem", "epm"), # getBrandOEM, "vuplus"
	("BRAND_OEM", "getBrandOEM"), # getBrandOEM
#	("BUILD_VERSION", "build", "epm"), # getImageBuild
	("BUILD_VERSION", "getImageBuild"), # getImageBuild
#	("DATETIME", "lastbuilddate", "epm"),
	("DATETIME", "getLastBuildDate"),  # not part of boxbranding
#	("DEFAULTTUNE", "imagearch", "epm"), # getImageArch
	("DEFAULTTUNE", "getImageArch"), # getImageArch
#	("DEVELOPER_BUILD_VERSION", "imagedevbuild", "epm"), # getImageDevBuild
	("DEVELOPER_BUILD_VERSION", "getImageDevBuild"), # getImageDevBuild
#	("DISPLAY_TYPE", "displaytype", "epm"), # getDisplayType
	("DISPLAY_TYPE", "getDisplayType"), # getDisplayType
#	("DISTRO_FEED_URI", "feedsurl", "epm"), # getFeedsUrl
	("DISTRO_FEED_URI", "getFeedsUrl"), # getFeedsUrl
#	("DISTRO_NAME", "imagedistro", "epm"), # getImageDistro
	("DISTRO_NAME", "getImageDistro"), # getImageDistro
#	("DISTRO_TYPE", "imagetype", "epm"), # getImageType
	("DISTRO_TYPE", "getImageType"), # getImageType
#	("HAVE_AV_JACK", "avjack", "epm"), # getHaveAVJACK
	("HAVE_AV_JACK", "getHaveAVJACK"), # getHaveAVJACK
#	("HAVE_CI", "ci", "epm"), # getHaveCI
	("HAVE_CI", "getHaveCI"), # getHaveCI
#	("HAVE_DVI", "dvi", "epm"), # getHaveDVI
	("HAVE_DVI", "getHaveDVI"), # getHaveDVI
#	("HAVE_HDMI", "hdmi", "epm"), # getHaveHDMI
	("HAVE_HDMI", "getHaveHDMI"), # getHaveHDMI
#	("HAVE_HDMI_IN_HD", "hdmiinhd", "epm"), # getHaveHDMIinHD
	("HAVE_HDMI_IN_HD", "getHaveHDMIinHD"), # getHaveHDMIinHD
#	("HAVE_HDMI_IN_FHD", "hdmiinfhd", "epm"), # getHaveHDMIinFHD
	("HAVE_HDMI_IN_FHD", "getHaveHDMIinFHD"), # getHaveHDMIinFHD
#	("HAVE_MINITV", "minitv", "epm"), # getHaveMiniTV
	("HAVE_MINITV", "getHaveMiniTV"), # getHaveMiniTV
#	("HAVE_RCA", "rca", "epm"), # getHaveRCA
	("HAVE_RCA", "getHaveRCA"), # getHaveRCA
#	("HAVE_SCART", "scart", "epm"), # getHaveSCART
	("HAVE_SCART", "getHaveSCART"), # getHaveSCART
#	("HAVE_SCART_YUV", "scartyuv", "epm"), # getHaveSCARTYUV
	("HAVE_SCART_YUV", "getHaveSCARTYUV"), # getHaveSCARTYUV
#	("HAVE_WOL", "wol", "epm"), # getHaveWOL
	("HAVE_WOL", "getHaveWOL"), # getHaveWOL
#	("HAVE_WWOL", "wwol", "epm"), # getHaveWWOL
	("HAVE_WWOL", "getHaveWWOL"), # getHaveWWOL
#	("HAVE_YUV", "yuv", "epm"), # getHaveYUV
	("HAVE_YUV", "getHaveYUV"), # getHaveYUV
#	("IMAGEDIR", "imagefolder", "epm"), # getImageFolder
	("IMAGEDIR", "getImageFolder"), # getImageFolder
#	("IMAGE_FSTYPES", "imagefilesystem", "epm"), # getImageFileSystem
	("IMAGE_FSTYPES", "getImageFileSystem"), # getImageFileSystem
#	("IMAGE_NAME", "imagename", "epm"), # 	e.g. "openvix-5.4.004.018.experimental-vuultimo4k"
	("IMAGE_NAME", "getImageName"), # not in boxbranding	e.g. "openvix-5.4.004.018.experimental-vuultimo4k"
#	("IMAGE_VERSION", "imageversion", "epm"), # getImageVersion
	("IMAGE_VERSION", "getImageVersion"), # getImageVersion
#	("KERNEL_FILE", "kernelfile", "epm"), # getMachineKernelFile
	("KERNEL_FILE", "getMachineKernelFile"), # getMachineKernelFile
#	("MACHINE", "model", "epm"), # set in conf/local.conf file in the Build Directory. 
	("MACHINE", "getModel"), # not in boxbranding, set in conf/local.conf file in the Build Directory. 
#	("MACHINEBUILD", "boxtype", "epm"), # getBoxType
	("MACHINEBUILD", "getBoxType"), # getBoxType, not the same as boxbrandin.getBoxType()
#	("MACHINEBUILD", "machinebuild", "epm"), # getMachineBuild
	("MACHINEBUILD", "getMachineBuild"), # getMachineBuild
#	("MACHINE_BRAND", "machinebrand", "epm"), # getMachineBrand
	("MACHINE_BRAND", "getMachineBrand"), # getMachineBrand
#	("MACHINE_NAME", "machinename", "epm"), # getMachineName
	("MACHINE_NAME", "getMachineName"), # getMachineName
#	("MKUBIFS_ARGS", "mkubifs", "epm"), #getMachineMKUBIFS
	("MKUBIFS_ARGS", "getMachineMKUBIFS"), #getMachineMKUBIFS
#	("MTD_KERNEL", "mtdkernel", "epm"), # getMachineMtdKernel
	("MTD_KERNEL", "getMachineMtdKernel"), # getMachineMtdKernel
#	("MTD_ROOTFS", "mtdrootfs", "epm"),  # getMachineMtdRoot
	("MTD_ROOTFS", "getMachineMtdRoot"),  # getMachineMtdRoot
#	("ROOTFS_FILE", "rootfile", "epm"), # getMachineRootFile
	("ROOTFS_FILE", "getMachineRootFile"), # getMachineRootFile
#	("SOC_FAMILY", "socfamily", "epm"),
	("SOC_FAMILY", "getSocFamily"), # not in boxbranding
#	("TRANSCODING", "transcoding", "epm"), # getHaveTranscoding1
	("TRANSCODING", "getHaveTranscoding1"), # getHaveTranscoding1
#	("UBINIZE_ARGS", "ubinize", "epm"), # getMachineUBINIZE
	("UBINIZE_ARGS", "getMachineUBINIZE"), # getMachineUBINIZE
]

env_vars.sort(key=lambda x: x[0])

check_duplicates = []
for env_var in env_vars:
	if env_var[1] in check_duplicates:
		import sys
		sys.exit("Error: duplication, %s already in env_vars" % env_var[1])
	check_duplicates.append(env_var[1])
del check_duplicates

f = open(outfile, "w+")

f.write("for epm_procfs.h\n----------------\n\n")

for env_var in env_vars:
	f.write("int get_%s(struct seq_file *m, void* data);\n" % env_var[1])

	
f.write("\n\n")

f.write("for epm_procfs_info.c\n---------------------\n\n")

for env_var in env_vars:
	f.write(
"""int get_%s(struct seq_file *m, void* data)
{
	seq_printf(m, "@%s@");
#ifdef DEBUG
	printk(KERN_INFO "%s=@%s@\\n");
#endif
	return 0;
}

""" % (env_var[1], env_var[0], env_var[1], env_var[0]))

directories = []



f.write("\n\n")

f.write("for epm_procfs_main.c\n---------------------\n\n")

f.write("struct ProcStructure_s _Proc[] =\n{\n")

for env_var in env_vars:
	if len(env_var) > 2 and  env_var[2] not in directories:
		f.write("""struct ProcStructure_s _Proc[] =\n{\n\t{cProcDir, "%s", NULL, NULL, NULL, NULL, ""},\n""" % env_var[2])
		directories.append(env_var[2])
del directories

 
for env_var in env_vars:
	f.write("""\t{cProcEntry, "%s%s", PROC_PERMISSION, get_%s, NULL, NULL, ""},\n""" % (env_var[2]+"/" if len(env_var) > 2 and  env_var[2] else "", env_var[1], env_var[1]))

f.write("};\n\n")



for env_var in env_vars:
	f.write("""\tprintk(KERN_INFO "%s=@%s@\\n");\n""" % (env_var[1], env_var[0]))

f.write("\n\n")

f.write("".join(["\\n%s=@%s@" % (env_var[1], env_var[0]) for env_var in env_vars]))

f.write("\n\n")

templist = []

f.write("for bitbake recipe\n------------------\n\n")

f.write("do_configure_prepend(){\n")
for env_var in env_vars:
	if  env_var[0] not in templist:
		templist.append(env_var[0])
		f.write('\tfind ${S}/ -type f -name "*.c" | xargs -r -L1 sed -i "s|@%s@|${%s}|g"\n' % (env_var[0], env_var[0]))
del templist
f.write("}\n\n")

f.write("for testing\n------------------\n\n")

for env_var in env_vars:
	try:
		out = open("/proc/%s%s" % ("%s/" % env_var[2] if len(env_var) > 2 and  env_var[2] else "", env_var[1])).read()
		f.write("`/proc/%s%s`, e.g. `%s`\n\n" % ("%s/" % env_var[2] if len(env_var) > 2 and  env_var[2] else "", env_var[1], out))
	except Exception as err:
		print('Error: %s "%s"' % (type(err).__name__, err))

f.close()
	