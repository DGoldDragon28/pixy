package org.usfirst.frc.team1719.pixyjni;

public class Pixy {
    static class PixyException extends Exception {
        private static final long serialVersionUID = -4471978923656082806L;
        final int errno;
        PixyException(int _errno) {
            errno = _errno;
        }
    }
    
    private static PixyJNI jni = new PixyJNI();
    
    public static void init() throws PixyException{
        int ret = jni.init();
        if(ret < 0) throw new PixyException(ret);
    }
    public static boolean blocksAreNew() {
        return (jni.blocksAreNew() > 0);
    }
    public static boolean getAutoExposureCompensation() throws PixyException{
        int ret = jni.getAutoExposureCompensation();
        if(ret < 0) throw new PixyException(ret);
        return (ret > 0);
    }
    public static boolean getAutoWhiteBalance() throws PixyException{
        int ret = jni.getAutoWhiteBalance();
        if(ret < 0) throw new PixyException(ret);
        return (ret > 0);
    }
    public static int getBrightness() throws PixyException{
        int ret = jni.getBrightness();
        if(ret < 0) throw new PixyException(ret);
        return ret;
    }
    public int[] getExposureCompensastion() throws PixyException{
        IntPtr gain = new IntPtr();
        IntPtr compensation = new IntPtr();
        int ret;
        ret = jni.getExposureCompensastion(gain, compensation);
        if(ret < 0) throw new PixyException(ret);
        return new int[] {gain.value, compensation.value};
    }
    public int getWhiteBalanceValue(){
        return jni.getWhiteBalanceValue();
    }
    public void setAutoExposureCompensation(boolean enable) throws PixyException{
        int ret = jni.setAutoExposureCompensation(enable);
        if(ret < 0) throw new PixyException(ret);
    }
    public void setAutoWhiteBalance(boolean enable) throws PixyException{
        int ret = jni.setAutoWhiteBalance(enable);
        if(ret < 0) throw new PixyException(ret);
    }
    public void setBrightness(int brightness) throws PixyException{
        int ret = jni.setBrightness(brightness);
        if(ret < 0) throw new PixyException(ret);
    }
    public void setExposureCompensation(int gain, int compensation) throws PixyException{
        int ret = jni.setExposureCompensation(gain, compensation);
        if(ret < 0) throw new PixyException(ret);
    }
    public void setWhiteBalanceValue(int r, int g, int b) throws PixyException{
        int ret = jni.setWhiteBalanceValue(r, g, b);
        if(ret < 0) throw new PixyException(ret);
    }
    public void close(){
        jni.close();
    }
    public void command(String name, Object ... varargs) throws PixyException{
        int ret = jni.command(name, varargs);
        if(ret < 0) throw new PixyException(ret);
    }
    public Block[] getBlocks(int max) throws PixyException{
        Block[] blocks = new Block[max];
        int ret = jni.getBlocks(max, blocks);
        if(ret < 0) throw new PixyException(ret);
        return blocks;
    }
    public int[] getFirmwareVersion() throws PixyException{
        IntPtr major = new IntPtr();
        IntPtr minor = new IntPtr();
        IntPtr build = new IntPtr();
        int ret;
        ret = jni.getFirmwareVersion(major, minor, build);
        if(ret < 0) throw new PixyException(ret);
        return new int[] {major.value, minor.value, build.value};
    }
    public int ledGetMaxCurrent() throws PixyException{
        int ret = jni.ledGetMaxCurrent();
        if(ret < 0) throw new PixyException(ret);
        return ret;
    }
    public void ledSetMaxCurrent(int current) throws PixyException{
        int ret = jni.ledSetMaxCurrent(current);
        if(ret < 0) throw new PixyException(ret);
    }
    public void ledSetRGB(int red, int green, int blue) throws PixyException{
        int ret = jni.ledSetRGB(red, green, blue);
        if(ret < 0) throw new PixyException(ret);
    }
}
