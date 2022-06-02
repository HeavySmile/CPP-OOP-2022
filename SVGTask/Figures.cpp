#include "Figures.hpp"

Shape* Figures::createShapeByName(const char* shape_name)
{
    if(!strcmp(shape_name, "rectangle") || !strcmp(shape_name, "rect"))
    {
        return new Rectangle();
    }
    else if(!strcmp(shape_name, "circle"))
    {
        return new Circle();
    }
    else if(!strcmp(shape_name, "line"))
    {
        return new Line();
    }
    else return nullptr;
}
Shape* Figures::cloneShape(const Shape* shape)
{
    Shape* to_return = shape->clone();
    return to_return;
}

Figures::Figures() : shapesLimit(INITIAL_SHAPES_LIMIT) 
{
    shapes = new Shape*[INITIAL_SHAPES_LIMIT];
    for (int i = 0; i < INITIAL_SHAPES_LIMIT; i++)
    {
        shapes[i] = nullptr;
    }
}
Figures::~Figures() 
{
    for (int i = 0; i < shapesLimit; i++)
    {
        delete shapes[i];
    }
    delete[] shapes;
}

void Figures::translate(const int shape_idx, const double x_change, const double y_change)
{
    Point point = shapes[shape_idx]->getStartPoint();
    
    point.setX(point.getX() + x_change);
    point.setY(point.getY() + y_change);
    
    shapes[shape_idx]->setStartPoint(point);
}
void Figures::translateAll(const double x_change, const double y_change)
{
    for (int i = 0; i < Shape::shapes_counter; i++)
    {
        translate(i, x_change, y_change);
    }
}
void Figures::create()
{
    if(Shape::shapes_counter == shapesLimit)
    {
        shapes = resizeArray(shapes, shapesLimit, shapesLimit*2);
        shapesLimit *= 2;
    }
    
    char shape_type[MAX_INPUT_SIZE];
    cin >> shape_type;

    delete shapes[Shape::shapes_counter];
    shapes[Shape::shapes_counter] = createShapeByName(shape_type);

    if(shapes[Shape::shapes_counter] == nullptr)
    {
        cout << "No such shape available" << endl;
        return;
    }

    shapes[Shape::shapes_counter++]->read(cin);
}
void Figures::erase()
{
    size_t figure_idx;
    cin >> figure_idx;

    for (int i = figure_idx - 1; i < Shape::shapes_counter - 1; i++)
    {
        delete shapes[i];
        shapes[i] = shapes[i + 1];
    }
    
    shapes[Shape::shapes_counter - 1] = nullptr;

    --Shape::shapes_counter;
}

void Figures::areas() const
{
    cout << endl;
    for (int i = 0; i < Shape::shapes_counter; i++)
    {
        cout << i + 1 << ". ";
        cout << "area = " << shapes[i]->getArea() << endl;
    }
    cout << endl;
}
void Figures::pers() const
{
    cout << endl;
    for (int i = 0; i < Shape::shapes_counter; i++)
    {
        cout << i + 1 << ". ";
        cout << "perimeter = " << shapes[i]->getPerimeter() << endl;
    }
    cout << endl;
}
void Figures::withinRectangle()
{
    double x, y, width, height;
    cin >> x >> y >> width >> height;

    for (int i = 0; i < Shape::shapes_counter; i++)
    {
        if(shapes[i]->withinRectangle(Point(x,y), width, height))
        {
            shapes[i]->print(cout);
        }
    }
}
void Figures::withinCircle()
{
    double x, y, radius;
    cin >> x >> y >> radius;

    for (int i = 0; i < Shape::shapes_counter; i++)
    {
        if(shapes[i]->withinCircle(Point(x,y), radius))
        {
            shapes[i]->print(cout);
        }
    }
}
void Figures::pointIn() const
{
    Point p_in;
    p_in.read(cin);

    for (int i = 0; i < Shape::shapes_counter; i++)
    {
        if(shapes[i]->pointIn(p_in))
        {
            cout << i + 1 << ". ";
            shapes[i]->print(cout);
            cout << endl;
        }
    }
}
void Figures::writeToFile(const char* filepath)
{
    ofstream file(filepath, ios::trunc);
    
    file << "<?xml version=\"1.0\" standalone=\"no\"?>" << endl;
    file << "<!DOCTYPE svg PUBLIC \"-//W3C//DTD SVG 1.1//EN\" \"http://www.w3.org/Graphics/SVG/1.1/DTD/svg11.dtd\">" << endl;
    file << "<svg>" << endl;
    
    for (int i = 0; i < Shape::shapes_counter; i++)
    {
        shapes[i]->writeToFile(file);
        file << endl;
    }
    file << "</svg>" << endl;
    file.close();
}
void Figures::readFromFile(const char* filepath)
{
    ifstream file(filepath);
    // int fileSize = file.tellg();
    // file.seekg(0);
    
    char* fileText = new char[MAX_INPUT_SIZE];
    
    bool insideSVG = false;
    do
    {
        file.getline(fileText, MAX_INPUT_SIZE);

        if(insideSVG && strcmp(fileText, "</svg>"))
        {
            char buffer[MAX_INPUT_SIZE];
            int i;
            for (i = 1; fileText[i] != ' '; i++)
            {
                buffer[i - 1] = fileText[i];
            }
            buffer[i - 1] = '\0';
            
            Shape* shape = createShapeByName(buffer);
            shape->readFromTag(fileText);
            
            delete shapes[Shape::shapes_counter];
            shapes[Shape::shapes_counter] = shape;
            shapes[Shape::shapes_counter]->print(cout);
            continue;            
        }

        if(!strcmp(fileText, "<svg>")) insideSVG = true;
    }
    while(strcmp(fileText,"</svg>"));
    
    delete[] fileText;
    file.close(); 
}
void Figures::print() const
{
    cout << endl;
    for (int i = 0; i < Shape::shapes_counter; i++)
    {
        cout << i + 1 << ". ";
        shapes[i]->print(cout);
        cout << endl;
    }
    cout << endl;
}