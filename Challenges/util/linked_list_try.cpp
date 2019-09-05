
#include "linked_list.hpp"
#include "point.hpp"

using namespace std;

int main(){

    Linked_List<Point> point_list;

    point_list.insert_last(new Point(0.1,0.1));
    point_list.insert_last(new Point(0.2,0.2));
    point_list.insert_last(new Point(0.3,0.3));
    point_list.insert_last(new Point(0.4,0.4));
    point_list.insert_last(new Point(0.5,0.5));
    point_list.insert_last(new Point(0.6,0.6));
    point_list.insert_last(new Point(0.7,0.7));
    point_list.insert_last(new Point(0.8,0.8));
    point_list.insert_last(new Point(0.9,0.9));

    point_list.remove_item(new Point(0.5,0.6));
    point_list.remove_item(new Point(0.4,0.4));

    point_list.print();

    cout << endl << "---------------------------------------" << endl << endl;

    for(int i = 0; i < point_list.get_size(); i++){
        cout << point_list.get_item(i) << endl;
    }

    return 0;
}
