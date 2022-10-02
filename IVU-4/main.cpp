#include <iostream>
#include <set>
#include <map>
#include <iterator>
#include <vector>
#include <list>
#include <fstream>
#include <algorithm>
#include <time.h>
#include <QFile>
#include <QJsonObject>
#include <QJsonDocument>
#include <QJsonArray>
#include <random>
#include <QVariant>
#include <QDebug>
/*
    Дан файл с английскими словами, разделёнными знаком '.'. Используя std::getline  или regex составить множество (std::set)
из уникальных слов в файле. Слова хранить в std::string.

Также составить словарь (std::map) по следующему принципу:
Ключ - буква, значение - количество слов, начинающихся на эту букву в файле

Сгенерировать список из 100 структур со следующими полями:
    Название - случайное слово из множества
    Основной параметр - используя std::advance получить значения трёх случайных элементов из словаря и перемножить их
    Вторичный параметр - квадрат значения из словаря, связанного с названием(в случае буквы брать первую букву названия)

??????Используя функции из библиотеки algorithms
Отсортировать список по убыванию названия

  Используя std::copy_if, создать новый список, содержащий только:
Элементы, содержащие максимальное значение вторичного параметра

Сгенерировать на основе полученного отфильтрованного списка файл формата json.
    Добавить возможность загрузки файла формата json, создания на основе данных в нём списка,
перетасовки (shuffle) его и отображения полученного результата.
Подключить библиотеку
Ввывод

*/

using namespace std;

struct Why
{
    string name;
    int par_1 ;
    int par_2 ;
};

ostream& operator << (ostream& afi,const Why &_why)
{
    cout << _why.name << " " << left <<_why.par_1 << " " << _why.par_2 << " "<<endl;
    return afi;
};

ostream& operator << (ostream& afi,list <Why>:: iterator &it_list)
{
    cout << (*it_list).name << " " << left <<(*it_list).par_1 << " " << (*it_list).par_2 << " "<<endl;
    return afi;
};

bool compare (const Why &a, const Why &b)
{
    return a.name[0]>b.name[0];
};




int main()
{
    system ("chcp 65001");
    set<string> _set;
    Why _Why;
    map <char, int> _map;
    list <Why> _list;
    list <Why> _list_two;
    list <Why> _list_tri;
    vector <Why> _vector;
    ifstream file;
    set <string> :: iterator it = _set.begin();
     map <char,int> :: iterator it_map = _map.begin();
     list  <Why> :: iterator it_list = _list.begin();
     list  <Why> :: iterator it_list_two = _list_two.begin();
      list  <Why> :: iterator it_list_tri = _list_tri.begin();
     QFile JsonFile("C:/Univirsity/erw3/first.json");
     JsonFile.open(QIODevice::ReadWrite);
     QFile JsonFile_2("C:/Univirsity/erw3/second.json");
     JsonFile_2.open(QIODevice::ReadWrite);


    string str;
    int k = 0;


    file.open("C:\\Univirsity\\IVU_4\\IVU4.txt");
  /*  Дан файл с английскими словами, разделёнными знаком '.'. Используя std::getline  или regex составить множество (std::set)
из уникальных слов в файле. Слова хранить в std::string.

Также составить словарь (std::map) по следующему принципу:
Ключ - буква, значение - количество слов, начинающихся на эту букву в файле*/
    while (!file.eof())
    {
        getline(file, str, '.');
        _set.insert(str);
        cout<<k++<<str[0]<<"  ";
        if (!file.eof()) _map[str[0]] ++;
    };
    file.close();
    k=0;
    for (const auto &i : _map) cout << i.first <<"-"<< i.second<< " ";cout<<endl;



    /*Сгенерировать список из 100 структур со следующими полями:
    Название - случайное слово из множества
    Основной параметр - используя std::advance получить значения трёх случайных элементов из словаря и перемножить их
    Вторичный параметр - квадрат значения из словаря, связанного с названием(в случае буквы брать первую букву названия)*/
    for (int i = 0; i < 100; ++i)
    {
        _Why.par_1 = 1; _Why.par_2 = 1;
        it = _set.begin();
        advance (it, rand() % _set.size());
        _Why.name = *it;

        it_map = _map.find(_Why.name[0]);
        _Why.par_2 = it_map->second * it_map->second;

        for (int j = 0; j < 3; ++j)
        {
          it_map = _map.begin();
         advance (it_map, rand() % _map.size());
        _Why.par_1 *= it_map->second;
        }
        _list.push_back(_Why);
        cout << i+1 << " " <<_Why;
        k = 0;
    };


cout << endl<<  endl<< "54646"<< endl<< endl ;
it_list = _list.begin();
    while (it_list != _list.end())
    {

       cout <<*it_list;
       it_list++;
    };

cout << endl<<  endl<< "54646"<< endl<< endl ;
/*??????Используя функции из библиотеки algorithms
Отсортировать список по убыванию названия*/
_list.sort(compare);
    it_list = _list.begin();
        while (it_list != _list.end())
        {
           cout <<*it_list;
           it_list++;
        };


/*  Используя std::copy_if, создать новый список, содержащий только:
Элементы, содержащие максимальное значение вторичного параметра*/
copy_if(_list.begin(), _list.end(), back_inserter(_list_two),[](const Why &a){return a.par_2 == 39*39;});
for (const auto &i: _list_tri) cout << i << " ";
cout << endl<<  endl<< "54646"<< endl<< endl ;

         QJsonArray jsonArray;
         QJsonObject jsonObject;
         it_list_two = _list_two.begin();
            while (it_list_two != _list_two.end())
            {
                QString Name = QString::fromStdString((*it_list_two).name);
                QString arg_1 = QString::number((*it_list_two).par_1);
                QString arg_2 = QString::number((*it_list_two).par_2);;
                // Используйте QJsonArray для добавления значения и записи в файл
            jsonObject.insert("name", Name);
            jsonObject.insert("par_1", arg_1);
            jsonObject.insert("par_2", arg_2);
            jsonArray.append(jsonObject);
               cout <<*it_list_two;
               it_list_two++;
            };
            QJsonDocument jsonDoc;
            jsonDoc.setArray(jsonArray);
            cout << "Write" << endl;
            JsonFile.write(jsonDoc.toJson());
            JsonFile.close();
/*Сгенерировать на основе полученного отфильтрованного списка файл формата json.
    Добавить возможность загрузки файла формата json, создания на основе данных в нём списка,
перетасовки (shuffle) его и отображения полученного результата.*/

            QByteArray val;
            val = JsonFile_2.readAll();
             JsonFile_2.close();
             QJsonParseError jspe{};
             const QJsonDocument doc = QJsonDocument::fromJson(val, &jspe);
             if (doc.isNull()) {
               qWarning() << "Error loading JSON:" << jspe.errorString() << "@" << jspe.offset;
             }
             if (doc.isArray())
               qDebug() << "Document is an array" << doc.array();

              jsonArray = doc.array();


             for (int i=0; i < jsonArray.size(); i++)
             {
                 QJsonObject temp =  jsonArray.at(i).toObject();
                 _Why.name =  temp.take("name").toString().toStdString();
                 _Why.par_1 =  temp.take("par_1").toString().toUInt();
                 _Why.par_2 =  temp.take("par_2").toString().toUInt();
                 _list_tri.push_back(_Why);
             }

cout << endl<<endl<<endl;

it_list_tri = _list_tri.begin();
    while (it_list_tri != _list_tri.end())
    {
       cout <<*it_list_tri;
       it_list_tri++;
    };

cout << 234 << endl;

    for(const auto &i: _list_tri) _vector.push_back(i);
    _list_tri.clear();
    random_device rd;
    mt19937 g(rd());
    shuffle(_vector.begin(),_vector.end(), g);
    for(const auto &i: _vector) _list_tri.push_back(i);
    for(const auto &i: _list_tri) cout << i;
     _vector.clear();
//JsonFile.close();
    return 0;
}
