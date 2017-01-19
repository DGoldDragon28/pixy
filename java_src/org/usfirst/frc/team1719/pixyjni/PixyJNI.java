package org.usfirst.frc.team1719.pixyjni;

public class PixyJNI {
    static {
        System.loadLibrary("libpixyusb");
    }
    public native int init();
    public native int blocksAreNew();
    public native int getAutoExposureCompensation();
    public native int getAutoWhiteBalance();
    public native int getBrightness();
    public native int getExposureCompensastion(IntPtr gain, IntPtr compensation);
    public native int getWhiteBalanceValue();
    public native int setAutoExposureCompensation(boolean enable);
    public native int setAutoWhiteBalance(boolean enable);
    public native int setBrightness(int brightness);
    public native int setExposureCompensation(int gain, int compensation);
    public native int setWhiteBalanceValue(int r, int g, int b);
    public native void close();
    public native int command(String name, Object[] varargs);
    public native int getBlocks(int max, Block[] blocks);
    public native int getFirmwareVersion(IntPtr major, IntPtr minor, IntPtr build);
    public native int ledGetMaxCurrent();
    public native int ledSetMaxCurrent(int current);
    public native int ledSetRGB(int red, int green, int blue);
}
