#include "epm_procfs.h"

int get_getBrandOEM(struct seq_file *m, void* data)
{
	seq_printf(m, "@BRAND_OEM@");
#ifdef DEBUG
	printk(KERN_INFO "getBrandOEM=@BRAND_OEM@\n");
#endif
	return 0;
}

int get_getImageBuild(struct seq_file *m, void* data)
{
	seq_printf(m, "@BUILD_VERSION@");
#ifdef DEBUG
	printk(KERN_INFO "getImageBuild=@BUILD_VERSION@\n");
#endif
	return 0;
}

int get_getLastBuildDate(struct seq_file *m, void* data)
{
	seq_printf(m, "@DATETIME@");
#ifdef DEBUG
	printk(KERN_INFO "getLastBuildDate=@DATETIME@\n");
#endif
	return 0;
}

int get_getImageArch(struct seq_file *m, void* data)
{
	seq_printf(m, "@DEFAULTTUNE@");
#ifdef DEBUG
	printk(KERN_INFO "getImageArch=@DEFAULTTUNE@\n");
#endif
	return 0;
}

int get_getImageDevBuild(struct seq_file *m, void* data)
{
	seq_printf(m, "@DEVELOPER_BUILD_VERSION@");
#ifdef DEBUG
	printk(KERN_INFO "getImageDevBuild=@DEVELOPER_BUILD_VERSION@\n");
#endif
	return 0;
}

int get_getDisplayType(struct seq_file *m, void* data)
{
	seq_printf(m, "@DISPLAY_TYPE@");
#ifdef DEBUG
	printk(KERN_INFO "getDisplayType=@DISPLAY_TYPE@\n");
#endif
	return 0;
}

int get_getFeedsUrl(struct seq_file *m, void* data)
{
	seq_printf(m, "@DISTRO_FEED_URI@");
#ifdef DEBUG
	printk(KERN_INFO "getFeedsUrl=@DISTRO_FEED_URI@\n");
#endif
	return 0;
}

int get_getImageDistro(struct seq_file *m, void* data)
{
	seq_printf(m, "@DISTRO_NAME@");
#ifdef DEBUG
	printk(KERN_INFO "getImageDistro=@DISTRO_NAME@\n");
#endif
	return 0;
}

int get_getImageType(struct seq_file *m, void* data)
{
	seq_printf(m, "@DISTRO_TYPE@");
#ifdef DEBUG
	printk(KERN_INFO "getImageType=@DISTRO_TYPE@\n");
#endif
	return 0;
}

int get_getHaveAVJACK(struct seq_file *m, void* data)
{
	seq_printf(m, "@HAVE_AV_JACK@");
#ifdef DEBUG
	printk(KERN_INFO "getHaveAVJACK=@HAVE_AV_JACK@\n");
#endif
	return 0;
}

int get_getHaveCI(struct seq_file *m, void* data)
{
	seq_printf(m, "@HAVE_CI@");
#ifdef DEBUG
	printk(KERN_INFO "getHaveCI=@HAVE_CI@\n");
#endif
	return 0;
}

int get_getHaveDVI(struct seq_file *m, void* data)
{
	seq_printf(m, "@HAVE_DVI@");
#ifdef DEBUG
	printk(KERN_INFO "getHaveDVI=@HAVE_DVI@\n");
#endif
	return 0;
}

int get_getHaveHDMI(struct seq_file *m, void* data)
{
	seq_printf(m, "@HAVE_HDMI@");
#ifdef DEBUG
	printk(KERN_INFO "getHaveHDMI=@HAVE_HDMI@\n");
#endif
	return 0;
}

int get_getHaveHDMIinFHD(struct seq_file *m, void* data)
{
	seq_printf(m, "@HAVE_HDMI_IN_FHD@");
#ifdef DEBUG
	printk(KERN_INFO "getHaveHDMIinFHD=@HAVE_HDMI_IN_FHD@\n");
#endif
	return 0;
}

int get_getHaveHDMIinHD(struct seq_file *m, void* data)
{
	seq_printf(m, "@HAVE_HDMI_IN_HD@");
#ifdef DEBUG
	printk(KERN_INFO "getHaveHDMIinHD=@HAVE_HDMI_IN_HD@\n");
#endif
	return 0;
}

int get_getHaveMiniTV(struct seq_file *m, void* data)
{
	seq_printf(m, "@HAVE_MINITV@");
#ifdef DEBUG
	printk(KERN_INFO "getHaveMiniTV=@HAVE_MINITV@\n");
#endif
	return 0;
}

int get_getHaveRCA(struct seq_file *m, void* data)
{
	seq_printf(m, "@HAVE_RCA@");
#ifdef DEBUG
	printk(KERN_INFO "getHaveRCA=@HAVE_RCA@\n");
#endif
	return 0;
}

int get_getHaveSCART(struct seq_file *m, void* data)
{
	seq_printf(m, "@HAVE_SCART@");
#ifdef DEBUG
	printk(KERN_INFO "getHaveSCART=@HAVE_SCART@\n");
#endif
	return 0;
}

int get_getHaveSCARTYUV(struct seq_file *m, void* data)
{
	seq_printf(m, "@HAVE_SCART_YUV@");
#ifdef DEBUG
	printk(KERN_INFO "getHaveSCARTYUV=@HAVE_SCART_YUV@\n");
#endif
	return 0;
}

int get_getHaveWOL(struct seq_file *m, void* data)
{
	seq_printf(m, "@HAVE_WOL@");
#ifdef DEBUG
	printk(KERN_INFO "getHaveWOL=@HAVE_WOL@\n");
#endif
	return 0;
}

int get_getHaveWWOL(struct seq_file *m, void* data)
{
	seq_printf(m, "@HAVE_WWOL@");
#ifdef DEBUG
	printk(KERN_INFO "getHaveWWOL=@HAVE_WWOL@\n");
#endif
	return 0;
}

int get_getHaveYUV(struct seq_file *m, void* data)
{
	seq_printf(m, "@HAVE_YUV@");
#ifdef DEBUG
	printk(KERN_INFO "getHaveYUV=@HAVE_YUV@\n");
#endif
	return 0;
}

int get_getImageFolder(struct seq_file *m, void* data)
{
	seq_printf(m, "@IMAGEDIR@");
#ifdef DEBUG
	printk(KERN_INFO "getImageFolder=@IMAGEDIR@\n");
#endif
	return 0;
}

int get_getImageFileSystem(struct seq_file *m, void* data)
{
	seq_printf(m, "@IMAGE_FSTYPES@");
#ifdef DEBUG
	printk(KERN_INFO "getImageFileSystem=@IMAGE_FSTYPES@\n");
#endif
	return 0;
}

int get_getImageName(struct seq_file *m, void* data)
{
	seq_printf(m, "@IMAGE_NAME@");
#ifdef DEBUG
	printk(KERN_INFO "getImageName=@IMAGE_NAME@\n");
#endif
	return 0;
}

int get_getImageVersion(struct seq_file *m, void* data)
{
	seq_printf(m, "@IMAGE_VERSION@");
#ifdef DEBUG
	printk(KERN_INFO "getImageVersion=@IMAGE_VERSION@\n");
#endif
	return 0;
}

int get_getMachineKernelFile(struct seq_file *m, void* data)
{
	seq_printf(m, "@KERNEL_FILE@");
#ifdef DEBUG
	printk(KERN_INFO "getMachineKernelFile=@KERNEL_FILE@\n");
#endif
	return 0;
}

int get_getModel(struct seq_file *m, void* data)
{
	seq_printf(m, "@MACHINE@");
#ifdef DEBUG
	printk(KERN_INFO "getModel=@MACHINE@\n");
#endif
	return 0;
}

int get_getBoxType(struct seq_file *m, void* data)
{
	seq_printf(m, "@MACHINEBUILD@");
#ifdef DEBUG
	printk(KERN_INFO "getBoxType=@MACHINEBUILD@\n");
#endif
	return 0;
}

int get_getMachineBuild(struct seq_file *m, void* data)
{
	seq_printf(m, "@MACHINEBUILD@");
#ifdef DEBUG
	printk(KERN_INFO "getMachineBuild=@MACHINEBUILD@\n");
#endif
	return 0;
}

int get_getMachineBrand(struct seq_file *m, void* data)
{
	seq_printf(m, "@MACHINE_BRAND@");
#ifdef DEBUG
	printk(KERN_INFO "getMachineBrand=@MACHINE_BRAND@\n");
#endif
	return 0;
}

int get_getMachineName(struct seq_file *m, void* data)
{
	seq_printf(m, "@MACHINE_NAME@");
#ifdef DEBUG
	printk(KERN_INFO "getMachineName=@MACHINE_NAME@\n");
#endif
	return 0;
}

int get_getMachineMKUBIFS(struct seq_file *m, void* data)
{
	seq_printf(m, "@MKUBIFS_ARGS@");
#ifdef DEBUG
	printk(KERN_INFO "getMachineMKUBIFS=@MKUBIFS_ARGS@\n");
#endif
	return 0;
}

int get_getMachineMtdKernel(struct seq_file *m, void* data)
{
	seq_printf(m, "@MTD_KERNEL@");
#ifdef DEBUG
	printk(KERN_INFO "getMachineMtdKernel=@MTD_KERNEL@\n");
#endif
	return 0;
}

int get_getMachineMtdRoot(struct seq_file *m, void* data)
{
	seq_printf(m, "@MTD_ROOTFS@");
#ifdef DEBUG
	printk(KERN_INFO "getMachineMtdRoot=@MTD_ROOTFS@\n");
#endif
	return 0;
}

int get_getMachineRootFile(struct seq_file *m, void* data)
{
	seq_printf(m, "@ROOTFS_FILE@");
#ifdef DEBUG
	printk(KERN_INFO "getMachineRootFile=@ROOTFS_FILE@\n");
#endif
	return 0;
}

int get_getSocFamily(struct seq_file *m, void* data)
{
	seq_printf(m, "@SOC_FAMILY@");
#ifdef DEBUG
	printk(KERN_INFO "getSocFamily=@SOC_FAMILY@\n");
#endif
	return 0;
}

int get_getHaveTranscoding1(struct seq_file *m, void* data)
{
	seq_printf(m, "@TRANSCODING@");
#ifdef DEBUG
	printk(KERN_INFO "getHaveTranscoding1=@TRANSCODING@\n");
#endif
	return 0;
}

int get_getMachineUBINIZE(struct seq_file *m, void* data)
{
	seq_printf(m, "@UBINIZE_ARGS@");
#ifdef DEBUG
	printk(KERN_INFO "getMachineUBINIZE=@UBINIZE_ARGS@\n");
#endif
	return 0;
}
