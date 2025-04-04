import java.awt.*;

public class Line implements IShape {
    // coordinates where to draw the line
    private double x;
    private double y;
    private Color color;
    private Color Fillcolor;
    private double thickness;
    private double length;

    public Line(double x, double y, Color color, Color fillcolor, double thickness, double length) {
        this.x = x;
        this.y = y;
        this.color = color;
        Fillcolor = fillcolor;
        this.thickness = thickness;
        this.length = length;
    }

    @Override
    public void draw(double x, double y) {
        System.out.println("Drawing a line ...");
    }

    public double getX() {
        return x;
    }

    public double getY() {
        return y;
    }

    public Color getColor() {
        return color;
    }

    public double getThickness() {
        return thickness;
    }

    public double getLength() {
        return length;
    }

    public Color getFillcolor() {
        return Fillcolor;
    }
}
