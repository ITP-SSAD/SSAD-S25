import java.awt.*;
import java.io.FileInputStream;
import java.util.HashMap;
import java.util.Map;

public class ShapeFactory {
    // Complete this code
    // Storing the collection of objects
    private static final Map<String, ShapeType> shapeMap = new HashMap<>();
    public static ShapeType getShapeType(Color color, Color fillcolor, double thickness){
        String key = color.toString() + fillcolor + thickness;
        // checking whether the shapeType is already created or not

        return shapeType;
    }
}
