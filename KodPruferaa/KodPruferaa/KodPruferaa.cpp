

#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

class Node //Узел дерева, должен содержать сссылку на родителя, информацию и список детей
{

public:
    int info; // Узел содержит целое число
    Node* parent; // Указатель на родительский узел
    vector <Node*> childs; // Массив детей
    Node(int info)
    {
        this->info = info;
        this->parent = nullptr;
    
    }
};
//--------------------------------------------------------------------------------------------

class Tree // Класс дерево
{
public:

    Node* root; //Ссылка на корень дерева
    int n; // Количество узлов в дереве
    vector <Node*> listiks;
    vector <int> prufer;

    Tree()
    {
        this->root = nullptr;
        this->n = 0;

    }



    Tree (Node* root)//Конструктор с параметром
    {
        this->root = root;
        this->n = 1;
    
    }
    void Add(Node* parent, Node* child) // К родителю нужно добавить ребёнка, это значит, что мы должны внести его в вектор детей родителя
    {
        parent->childs.push_back(child); //Добавили ребёнка в вектор родителя
        // У этого ребёнка нужно указать его родителя
        child->parent = parent;
        n++;
    
    
    }
    //Вывод одного узла
    void print1(Node* p) // p указатель на узел
    {
        cout << "     " << p->info << endl;
    }
    //Вывод всего дерева (поддерева) с узла p
    void print(Node* p, int tab = 0)
    {
        print1(p); // Выводим информацию о узле
        for (int i = 0; i < p->childs.size(); i++) {
            for (int k = 0; k <= tab; k++) printf("\t");//цикл сдвига на табуляцию
            print(p->childs[i], ++tab);
            --tab;
        }
    }

    void create()
    {
        Node* r1 = new Node(1);
        Node* r2 = new Node(6);
        Node* r11 = new Node(7);
        Node* r12 = new Node(8);
        Node* r21 = new Node(5);
        Node* r211 = new Node(4);
        Node* r212 = new Node(9);
        Node* r213 = new Node(3);
        Add(root, r1);
        Add(root, r2);
        Add(r1, r11);
        Add(r1, r12);
        Add(r2, r21);
        Add(r21, r211);
        Add(r21, r212);
        Add(r21, r213);
    


    
    }
    
    Node* delete_listok(Node* listok) //Передаём указатель на узел листок для уничтожения
    {
        //Листок нужно удалить из вектора родителя
        // И сам уничтожить
        Node* parent = listok->parent;
        vector<Node*>::iterator it = find(parent->childs.begin(), parent->childs.end(), listok);//ищем в векторе детей родителя данного ребенка       
        parent->childs.erase(it);//уничтожаем этого ребенка у родителя
        delete listok; //Освобождаем память
        listok = nullptr;
        n--;// количество узлов на 1 меньше. n - количество узлов в дереве
        return parent;

    }
    Node* Find_Node_by_info(Node* p, int info)//Программа находит по заданному значению узел дерева
    {
        if(p->info == info)
        {
            return p;
        
        }
        //Если в узле p не нашли, то ищем у детей
        for (int i = 0; i<p->childs.size();i++)
        {
            Node* p_find= Find_Node_by_info(p->childs[i],info);
            if (p_find != nullptr)
            {
                return p_find;
            }
           
        }
        return nullptr;
        
   
    
    }

    // Функция изменяет значения в узлах дерева
    void change_info() //Нужно находить нужные элементы по старому значению, и менять в них значения на новые
    {
        vector <int> v_new = { 7,6,5,4,3,2,1,8,9 }; // Новые значения в узлах, каторые соответсвуют 123456789
        vector <Node*> nodes; //Запоминаем все узлы по порядку их значний
        for (int i = 1; i<=9;i++)
        {
            nodes.push_back(Find_Node_by_info(root, i)); // Это список адресов узлов
        
        }
        //Теперь заменим в этом спеске узлов значения
        for (int i =0; i<=8; i++)
        {
            nodes[i]->info = v_new[i];
        
        }

    }

    vector <Node*> get_listiks(Node* p)
    {
        listiks.clear();
        // Сюда добавить случай, когда корень становится листом, в этом случае корень нужно добавлять в список листьев

        get_list_of_listiks(p);
        if (root->childs.size() == 1)// Если у корня один ребёнок, то он является листом (В смысле Пьюфера) 
        {
            listiks.push_back(root);
        
        }
        return listiks;

    
    
    }
    vector <Node*> get_list_of_listiks(Node* p)
    {
        if(p->childs.size() == 0)
        {
            listiks.push_back(p);// База рекурсии
        }
        for (int i = 0; i < p->childs.size(); i++)
        {
            get_list_of_listiks(p->childs[i]);

        }
        return listiks;
    
    }

    void print_listiks()// Печатает листки дерева
    {
        cout << "Листья дерева \n";
        for(int i = 0; i < listiks.size();i++)
        {
            cout << listiks[i]->info << " ";
        
        }
        cout << endl;
    
    }

    Node* find_min_listiks()//Находит листик с минимальным значением
    {

        int min = 1000;
        Node* pmin = nullptr;
        for (int i = 0; i<listiks.size(); i++)
        {
            if(listiks[i]->info < min)
            {
                min = listiks[i]->info;
                pmin = listiks[i];
            }
        
        }

        return pmin;

    }

    void print_prufer()
    {
        for(int i = 0; i<prufer.size();i++)
        {
            cout << prufer[i] << " ";
        
        
        }
        cout << endl;
    
    
    }



    Node* delete_root_with_one_child()
    {
        if(root->childs.size()!=1)
        {
            cout << "Удаление невозможно! Корень не является листом!\n";
            return nullptr;
        }
        // нужно сделать корнем его ребёнка и удалить старый корень
        Node* child = root->childs[0];
        delete root; //Освобождаем память
        root = child;
        root->parent = nullptr;
        n--;
        return root;
    
    }



    // Получает код Прюфера из дерева
    vector <int> get_pruf_cod()
    {
        
        // Создать вектор для записи кода Prufer +
        //1 Найти наименьший лепесток +
        //3 Удалить данный лепесток 
        //2 Записать информацию родителя в вектор prufer
        //4 повторять цикл n-2
        // Необходимое дополнение: нужна функция, которая создаёт список листьев
        int N = n - 2;
        for (int i = 0; i < N; i++)
        {
            get_listiks(root);
            print_listiks();
            cout << "----------------------------------\n";
            Node* pmin = find_min_listiks();
            Node* parmin; // указатель на родителя с минимальным параметром

            if (pmin != root)
            {
                parmin = delete_listok(pmin);

            }
            else
            {
                parmin = delete_root_with_one_child();

            }
            prufer.push_back(parmin->info);
            print(root);
            cout << "----------------------------------\n";
            print_prufer();
            cout << "----------------------------------\n";

        }
        print_prufer();
        

        


        return prufer;

    }
    

};



//Функция на вход которой подаётся вектор целых чисел, она ищет минимальное из отсутствующих
// Вункция возвращает это отсутствующее числа
int find_min_absent(vector <int> v)
{
    //В диапозоне размер вектора +2
    // В цикле 1 до последнего, если его нет, то возвращаем его
    for(int ind = 1;ind<=v.size()+2;ind++)
    {
        bool flag = false; //Если найдёт, то true
       for(int i = 0; i<v.size(); i++)
       {
            if(ind==v[i])
            {
                flag = true;
                break;
            
            }

       
       }
       if (!flag)
       {
           return ind;
       }
    
    }
    



}

//Функция создаёт список смежности из кода Прюфера, на вход подаётся вектор целых чисел, на выход подаётся вектор векторов целых чисел
vector <vector <int>> get_smeg_by_cod_prufer(vector <int> v)
{
    vector <vector <int>> smeg; //Это список смежности
    int N = v.size() + 2; //Число вершин дерева
    for (int i = 0; i<N; i++)
    {
        vector <int> a;
        smeg.push_back(a);
        
    
    
    }
    
    //Строем список смежности
        //1 Найдём минимальное в отсутсвующее в векторе v -ind +
        //2 Вычёркиваем из вектора v, первый элемент - front +
        //3 Запишем минимальное отсутсвующее в вектор v +
        //4 Добавить в вектор смежности соответствующие вершины +
        //5 Повторить цикл (размер вектора) раз +
    for(int i = 0; i<v.size();i++)
    {
        int ind = find_min_absent(v);
        int front = v[0];
        v.erase(v.begin()); //Удаляет первое число из вектора
        v.push_back(ind);
        smeg[ind-1].push_back(front);
        smeg[front-1].push_back(ind);

    
    }
    // Теперь добавим ребро из двух вершин, отсутствующих в текущем векторе v
    int first_absent = find_min_absent(v);
    v.push_back(first_absent);
    int second_absent = find_min_absent(v);
    smeg[first_absent - 1].push_back(second_absent);
    smeg[second_absent - 1].push_back(first_absent);

    return smeg;


}

void print_smeg(vector <vector <int>> smeg)
{
    cout << "---------------------Список смежности------------------------\n";
    for(int i = 0; i<smeg.size(); i++)
    {
        cout << i + 1 << ": ";
        for(int j = 0;j<smeg[i].size();j++)
        {
            cout << smeg[i][j] << " ";
        
        }
        cout << endl;
    
    
    }




}
//Проверяет на наличие данное значение в векторе, если есть, то возвращает True
bool is_in_using(vector <int> using_nodes, int ind)
{
   
   for(int i = 0; i<using_nodes.size();i++)
   {
        if(ind==using_nodes[i])
        {
            return true;
        
        }
   }
   return false;

}


void create_by_smeg(vector <vector <int>> smeg, vector <int> using_nodes, Tree& tree, Node* p)// Поскольку дерево будем меняится, ставим имперсанд (ссылка), и передаём по адресу
{
    if (using_nodes.size() == smeg.size()) // когда все узлы использованны
    {
        return;
    }
    for(int i = 0; i < smeg[p->info-1].size(); i++) // p->info номер, который содержится в узле p
    {
        int ind = smeg[p->info - 1][i]; //Номер ребёнка
        //Проверим, использовался номер ребёнка или нет
        if (!is_in_using(using_nodes, ind))
        {
            Node* child = new Node(ind);
            tree.Add(p, child); //Строем ребро между родителем и ребёнком
            using_nodes.push_back(ind);
            create_by_smeg(smeg, using_nodes, tree, child);
        
        }
    
    }

}
                                                                                              
                                                                                              //Создает дерево по списку смежности, проинимает так же информацию узла корня
Tree& create_tree_by_list_of_smeg(vector <vector <int>> smeg, int root_info)
{
    //1 Создать узел root. Создать дерево по этому узлу +
    //2 Звсести вектор, куда будем добавлять уже добавленные узлы. Добавить узел root
    //3 Пройтись по списку смежных и добавить детей, кроме самого узла
    //4 Повторить это для детей -: пройтись по списку смежных и добавлять детей, кроме всех уже добавленных узлов
    Node* root = new Node(root_info);
    Tree tree(root);

    vector <int> using_nodes; // вектор использованных узлов
    using_nodes.push_back(root_info);
    
    create_by_smeg(smeg, using_nodes, tree, root); 
    return tree;
}


// Главная программа Декодера
Tree create_tree_by_cod_prufer(vector <int> prufer) //Эта программа по коду Прюфера строит дерево 
{
    //1 получаем список смежности по коду Прюфера
    //2 По коду Прюфера формируем дерева
    vector <vector <int>> smeg;
    smeg = get_smeg_by_cod_prufer(prufer);
    print_smeg(smeg);
    Tree tree; // Создаём пустой объект дерева
    tree = create_tree_by_list_of_smeg(smeg,6); //Создаём дерево по списку смежности
    return tree;




}






int main()
{
    setlocale(LC_ALL, "rus");
    cout << "Hello World!\n";

    /*Node* root = new Node(2);
    Tree tree(root);
    //tree.print(root);
    tree.create();
    tree.print(root);
    cout << "-------------------------------------------\n";
    tree.change_info();
    tree.print(root);
    //tree.get_listiks(root);
    //tree.print_listiks();
    //Node* w = tree.find_min_listiks();
    //int ww = w->info;
    //cout << ww;
    tree.get_pruf_cod();
    */
    Node* root = new Node(2);
    Tree tree(root);
    //tree.print(root);
    tree.create();
    tree.print(root);
    tree.change_info();
    cout << "-----------------------------------\n";
    tree.print(root);
    tree.get_listiks(root);
    tree.print_listiks();
    cout << "----------------------------------------\n";
    tree.get_pruf_cod();
    cout << "////////////////////////////////////////////////\n";
    cout << "              " << "Декодер\n";
    cout << "////////////////////////////////////////////////\n";
    vector <int> prufer = { 7,3,3,7,6,2,3 };
    Tree treee;
    treee = create_tree_by_cod_prufer(prufer);
    cout << "-------------------------------------------------\n";
    treee.print(treee.root);
    

    
   // Node* p = tree.Find_Node_by_info(root, 4);
   // cout << p->info;
   
    





}

