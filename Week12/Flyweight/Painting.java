import java.awt.*;

public class Painting {
    public static void main(String[] args) {
        IShape line = new Line(2.2, 3.0,Color.LIGHT_GRAY,Color.GRAY,5, 10 );
        IShape circle = new Circle(2.2, 3.0,Color.LIGHT_GRAY,Color.GRAY,5, 10 );
    }
}
