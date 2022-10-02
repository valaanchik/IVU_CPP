#include <iostream>


/*
    Класс: Рациональное число
    Поля: числ. знам.
    Методы: операция преведения типа к double
    Операторы: сложение += увелечиние значения на величину действительного числа,
    сравнение == рационального числа сдействительным, сравнение >
*/

using namespace std;

class Rational {
    int nominator, denominator;
public:


    friend istream &operator>> (istream &cin, Rational &cur);
    friend ostream &operator<< (ostream &cout, const Rational &cur);
    friend void deist (double dei, double eps, Rational &cur);

    Rational(const int& a = 0, const int& b = 1): nominator(a), denominator(b){
     cout << "Конструктор с параметрами" << endl;
}


    Rational(const Rational &cur) : nominator(cur.nominator), denominator(cur.denominator){
           cout << "Конструктор копирования" << endl;

}


    ~Rational (){

       cout << "Деструктор" << endl;

    };

    void setNominator (const int a){

        nominator = a;
        cout << "Метод инициализации числителя" << endl;

    };

    void setDenominator (const int b){

        denominator = b;
        cout << "Метод инициализации знаменателя" << endl;

    };

    int getNominator (){

        cout << "Метод получения числителя" << endl;
        return nominator;
    };

    int getDenominator(){

        cout << "Метод полученя знаменателя" << endl;
        return denominator;
    };


    operator double() const
   {
         cout << "double()" << endl;
   return (static_cast<double>(this -> nominator))/this -> denominator;
   };

    // *this - ссылка на себя а this - указатель не путать!!


    Rational operator += (const Rational &RSecond){
        if (this -> denominator != RSecond.denominator){

            this -> nominator = this -> nominator * RSecond.denominator + RSecond.nominator * this -> denominator;
            this -> denominator = this ->denominator * RSecond.denominator;

        }
        else this -> nominator = this -> nominator + RSecond.nominator;
    cout << "+=" << endl;
    return *this;
    };


    bool operator == (const double &r){
        cout << "==" << endl;
        return double(*this)  == double(r);
               // return (this->nominator/Rsecond.nominator == this->denominator/Rsecond.denominator ? 1 : 0);


        };

    bool operator > (const double &r){
        cout << ">" << endl;
        return (double(*this)  > r ? 1 : 0);

        };


};


ostream &operator<< (ostream& cout, const Rational &cur){

    cout << "Рациональное число" << endl  << endl  <<  cur.nominator << "/" << cur.denominator << endl << endl;
    return cout;
};

istream &operator>> (istream& cin, Rational &cur){
    cout << "Ввод рационального числа." << endl << "Введите Числитель: ";
    cin >> cur.nominator;
    cout << "Введите знаменатель: ";
    cin >> cur.denominator;
    cout << endl;
    return cin;

};


void deist (double dei, double eps, Rational &cur){ //  Функция перевода действительного числа в рациональную дробь
      int a = 1; // числитель
      int b = 0; // знаменатель
      int mn = 2; // множитель для начального приближения
      int iter = 0;
      cur.nominator = a;
      cur.denominator = b;
      // Поиск начального приближения
      double c = 1;
      do {
        b++;
        c = (double)a / b;
      } while ((dei - c) < 0);
      if ((dei - c ) < eps)
      {
        cur.nominator = a; cur.denominator = b;
        return;
      }
      b--;
      c = (double)a / b;
      if ((dei - c) > -eps)
      {
        cur.nominator = a; cur.denominator = b;
        return;
      }
      // Уточнение
      while (iter < 10000000)
      {
        int cc = a*mn, zz = b*mn;
        iter++;
        do {
          zz++;
          c = (double)cc / zz;
        } while ((dei - c) < 0);
        if ((dei - c) < eps)
        {
          cur.nominator = cc; cur.denominator = zz;
          return;
        }
        zz--;
        c = (double)cc / zz;
        if ((dei - c) > -eps)
        {
          cur.nominator = cc; cur.denominator = zz;
          return;
        }
        mn++;
      }
    }; // Не очивидность прощне реализация затраты ресурсов


int main()
{
    system ("chcp 65001");

        int choice, s = 1;
        int nom, denom, ger;
        double real;
        Rational* num = new Rational;
        Rational* secnum = new Rational;

        do{


        cout << "1. Введение рационального числа." << endl;

        cout << "2. Изменить числитель." << endl;

        cout << "3. Изменить знаменатель." << endl;

        cout << "4. Перегрузка операции приведения типа к doublе." << endl;

        cout << "5. Операция '+=' присваивания рационального числа с действительным." << endl;

        cout << "6. Сравнение \"==\" рационального числа с действительным" << endl;

        cout << "7. Сравнение \"<\" рационального числа с действительным" << endl;

        cout << "8. Вывод рационального числа" << endl;

        cout << "0. Выход" << endl;

        cout << "\nВведите пункт меню: ";

        // Проверка

        while (!(cin >> choice) || choice < 0 || choice > 9)

        {

        cout << endl << "Ошибка: выбран несуществующий пункт меню." << endl;
        cout << "Пункт меню:  ";

        }

        system("CLS");


        switch(choice){
        case 0:

        s = 0;
        delete num;
        delete secnum;
        cout << "Программа завершена. ";

        break;

        case 1:

        cin >> *num;
        cout << *num << endl;

        break;

        case 2:

        cout << "Введите новый числитель: ";
        cin >> nom;
        num->setNominator(nom);
        cout << *num << endl;

        break;

        case 3:

        cout << "Введите новый знаменатель: ";
        while ((cin >> denom) && denom == 0)

        {

        cout << endl << "Ошибка: Знаменатель не должен быть равен нулю." << endl;
        cout << "Введите новый знаменатель: ";
        }

        num -> setDenominator(denom);
        cout << *num << endl;

        break;

        case 4:

        double result;

        cout << "\nПерегрузка операции приведения типа к doublе. \n"<< endl;
        result = double(*num);
        cout << "Результат приведения: " << result << endl << endl;

        break;

        case 5:

        cout << "Введите действительное число\n";
       if  (cin >> real && real != 0)
        deist(real,0.00000001,*secnum);

       *num += *secnum;
        cout << *num << endl;

        break;


        case 6:

        cout << "Введите действительное число\n";
        if  (cin >> real && real != 0)
        deist(real,0.001,*secnum);
            if (*secnum == *num) cout << "Pавны" << endl;
            else cout << "Не равны\n" << endl;


        break;


        case 7:

            cout << "Введите действительное число\n";
           cin >> real;
           if (double(*num) > real ) cout << "Действительное число меньше дроби.\n" << endl;
            else cout << "Действительное число не меньше дроби. \n" << endl;


        break;


        case 8:

            cout << "Вывод рационального числа\n";
           cout << *num << endl<< endl;

        break;


        default: cout << "Некорректный ввод";

        }


        }while(s);

    return 0;
};
