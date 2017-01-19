package org.usfirst.frc.team1719.pixyjni;

public class Block {
    int type;
    int signature;
    int x;
    int y;
    int width;
    int height;
    int angle;
    Block(int _type, int _signature, int _x, int _y, int _width, int _height, int _angle) {
        type = _type;
        signature = _signature;
        x = _x;
        y = _y;
        width = _width;
        height = _height;
        angle = _angle;
    }
}
