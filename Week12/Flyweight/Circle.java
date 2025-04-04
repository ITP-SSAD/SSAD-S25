import java.awt.*;

public class Circle implements IShape {

    private double x;
    private double y;
    private Color color;
    private Color Fillcolor;
    private double thickness;
    private double radius;

    public Circle(double x, double y, Color color, Color fillcolor, double thickness, double radius) {
        this.x = x;
        this.y = y;
        this.color = color;
        Fillcolor = fillcolor;
        this.thickness = thickness;
        this.radius = radius;
    }

    @Override
    public void draw(double x, double y) {
        System.out.println("Drawing a circle...");

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

    public Color getFillcolor() {
        return Fillcolor;
    }

    public double getThickness() {
        return thickness;
    }

    public double getRadius() {
        return radius;
    }
}
