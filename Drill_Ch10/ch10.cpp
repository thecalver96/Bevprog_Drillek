#include "../std_lib_facilities.h"

struct Point
{
    int x;
    int y;
};

ostream& operator<<(ostream& os, Point& p)
{
    return os << p;

}

void data_in( vector<Point>& p)
{
    int x, y = 0;
    for(int i = 0; i < 7; i++)
    {
    cin >> x >> y;
    p.push_back(Point{x,y});
    }
}

void print_points(vector<Point>& p)
{
    for(const auto& points : p)
        cout << points.x << " " << points.y << '\n';
}
void write_to_file(vector<Point>& p)
{

    ofstream out_file {"mydata.txt"};

    for(const auto& points : p)
        out_file << points.x << " " << points.y << '\n';

    out_file.close();
}
void read_to_vector(vector<Point>& p)
{
    int x, y = 0;
    ifstream in_file {"mydata.txt"};
    while(in_file >> x >> y)
    {
        p.push_back(Point{x,y});
    }

}

bool compare_vectors(vector<Point>& p, vector<Point>& q)
{
    if(p.size() != q.size())
    {
        cout << "Error! vectors differ in size!\n";
        return 0;
    }
    else
    {
        for(int i = 0; i < p.size(); ++i)
        {
            if (( p[i].x != q[i].x ) || (p[i].y != q[i].y ) )
                {
                    cout << "Error! vectors differ in value!\n";
                    return 0;
                }
        }
    }
return 1;
}

int main()
{

    vector <Point> original_points {0};
    vector <Point> processed_points {0};

    cout << "Please enter 7 pair of numbers (x y)\n";
    data_in(original_points);

    cout << '\n';
    cout << "Original points: \n";
    print_points(original_points);
    cout << '\n';

    write_to_file(original_points);
    read_to_vector(processed_points);

    cout << "Processed points: \n";
    print_points(processed_points);
    cout << '\n';

    if ( compare_vectors(original_points, processed_points) )
        cout << "Success!\n";

    return 0;
}
