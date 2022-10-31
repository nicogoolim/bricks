// bricks.cpp : Этот файл содержит функцию "main". Здесь начинается и заканчивается выполнение программы.
//

#include <iostream>
#include <vector>


 struct newWall{
 public:
    int x, y;
    int range;
    bool direct; // true = down, false = left;
    newWall(int x, int y, bool d) {
        this->x = x;
        this->y = y;
        this->direct = d;
    }
};
 std::vector<std::vector<int>> findRangeDown(std::vector<std::vector<int>> arr) {
     
     std::vector<std::vector<int>> ranges;
     for (int i = 0; i < arr.size(); i++)
     {
         std::vector<int> row;
         for (int j = 0; j < arr[0].size(); j++)
         {
             int DownRange = 0;
             int k = i;
             while (k != arr.size() && arr[k][j] != 1) {//check down
                 DownRange++;
                 k++;
             }
             row.push_back(DownRange);
         }
         ranges.push_back(row);
     }
     return ranges;
 }
 std::vector<std::vector<int>> findRangeleft(std::vector<std::vector<int>> arr) {

     std::vector<std::vector<int>> ranges;
     for (int i = 0; i < arr.size(); i++)
     {
         std::vector<int> row;
         for (int j = 0; j < arr[0].size(); j++)
         {
             int DownRange = 0;
             int k = j;
             while (k != arr.size() && arr[i][k] != 1) {//check left
                 DownRange++;
                 k++;
             }
             row.push_back(DownRange);
         }
         ranges.push_back(row);
     }
     return ranges;
 }
 newWall findMax(std::vector<std::vector<int>> left, std::vector<std::vector<int>> down) {
     int lMax = 0;
     newWall leftC(0,0,0);
     int dMax = 0;
     newWall downC(0, 0, 1);
     for (int i = 0; i < left.size(); i++)
     {
         for (int j = 0; j < left[0].size(); j++)
         {
             if (left[i][j]>lMax)
             {
                 lMax = left[i][j];
                 leftC.x = i;
                 leftC.y = j;
                 leftC.range = lMax;

             }
             if (down[i][j] > dMax)
             {
                 dMax = down[i][j];
                 downC.x = i;
                 downC.y = j;
                 downC.range = dMax;

             }
         }
     }
     int s = 1;
     if (lMax>dMax)
     {
         return leftC;
     }
     return downC;
 }
 std::vector<std::vector<int>> fillWalls(std::vector<std::vector<int>> walls, newWall newWalls) {
     if (newWalls.direct)
     {
         for (int i = newWalls.x; i < newWalls.x+newWalls.range; i++)
         {
             walls[i][newWalls.y] = 1;
         }
     }
     else {
         for (int i = newWalls.y; i < newWalls.y+newWalls.range; i++)
         {
             walls[newWalls.x][i] = 1;
         }
     }
     return walls;
 }
int main()
{
    int m, n;
    
    char ch;
    std::vector<std::vector<int>> walls;
    std::cin >> m >> n;

    for (int i = 0; i < m; i++)
    {
        std::vector<int> wall;
        for (int j = 0; j < n; j++)
        {
            std::cin >> ch;
            if (ch=='#')
            {
                wall.push_back(1);
            }
            if (ch=='.')
            {
                wall.push_back(0);
            }
        }
        walls.push_back(wall);
    }
   
    auto left = findRangeleft(walls);
    auto down = findRangeDown(walls);
    auto c = findMax(left, down);
    walls = fillWalls(walls, c);
    auto left1 = findRangeleft(walls);
    auto down1 = findRangeDown(walls);
    auto c1 = findMax(left1, down1);
    walls = fillWalls(walls, c1);
    std::cout << c.range + c1.range;
}

// Запуск программы: CTRL+F5 или меню "Отладка" > "Запуск без отладки"
// Отладка программы: F5 или меню "Отладка" > "Запустить отладку"

// Советы по началу работы 
//   1. В окне обозревателя решений можно добавлять файлы и управлять ими.
//   2. В окне Team Explorer можно подключиться к системе управления версиями.
//   3. В окне "Выходные данные" можно просматривать выходные данные сборки и другие сообщения.
//   4. В окне "Список ошибок" можно просматривать ошибки.
//   5. Последовательно выберите пункты меню "Проект" > "Добавить новый элемент", чтобы создать файлы кода, или "Проект" > "Добавить существующий элемент", чтобы добавить в проект существующие файлы кода.
//   6. Чтобы снова открыть этот проект позже, выберите пункты меню "Файл" > "Открыть" > "Проект" и выберите SLN-файл.
