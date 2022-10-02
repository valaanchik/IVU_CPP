/*
Доп. методы для класса "Строка-индификатор" : перевод всех символов строки, кроме цифр, в верхний регистр
переопределение операции >

Производный от "строки" класс Десятичная строка
Строки данного класса могут содержать только цифры десятичных цифр и символы (+,-) задающие знак числа, которые
могут находиться только перед числом, при отсутствии знака число положительное. Если в составе инициализирующей
строки будут встречены др. символы, то Д. строка принимает нулевое; Содержимое данных строк рассматривать,
как десятичное число.

Методы: определение, можно ли представить данное число в формате unsingend long, проверка на больше

Описать 3 класса  "Строка" произвдный строка-индификатор + д.строка

Поля класса «Строка»: указатель на блок динамически выделенной
памяти для размещения символов строки, длина строки в байтах. Обязательные методы, помимо вышеуказанных:
 конструктор, принимающий в качестве параметра символ (char), функция получения длины строки.

Строки класса «Строка-идентификатор» строятся по правилам
записи идентификаторов в Си, и могут включать в себя только те символы,
которые могут входить в состав Си-идентификаторов. Если исходные
данные противоречат правилам записи идентификатора, то создается
пустая «Строка-идентификатор».
Помимо обязательных компонентов классов, указанных в общей
постановке задачи и в вариативной его части, при необходимости можно
добавить дополнительные поля и методы.
Написать тестовую программу, которая должна:
динамически выделить память под массив указателей на базовый класс
(4-6 шт.);
в режиме диалога заполнить этот массив указателями на производные
классы, при этом экземпляры производных классов должны создаваться
динамически с заданием начальных значений;
для созданных экземпляров производных классов выполнить проверку
всех разработанных методов с выводом исходных данных и результатов
на дисплей.
*/



#include <iostream>
//#include <string>
//#include <cstring>


using namespace std;

class String {
int copyString;
public:
    int _length;
    char *str;
    /*
   Тип строки:
   0 - пустая строка
   1 - строка
   2 - строка идентификатор
   3 - десятичная строка
    */
    char type;
public:

    String (){
        cout << "Конструктор без параметра"<< endl;
        _length = 0;
        str = nullptr;
        type = 1;
    };

    String(const char *s)
    {
   cout << "String: конструктор, принимающий в качестве параметра Си-строку" << endl;

      for (_length = 0; s[_length] != '\n'; _length++) str = new char[_length];

      for (int i = 0; i < _length; i++) str[i] = s[i];
  type = 1;

    }

    String(char c)
    {
   cout << "String: конструктор, принимающий в качестве параметра символ (char)" << endl;

   _length = 1;
   str = new char[_length];
   str[0] = c;
   type = 1;
    }

    String(const String &s)
    {
    copyString++;
   cout << "String: конструктор копирования отработал " << copyString << endl;

   _length = s._length;
   str = new char[_length];

      for (int i = 0; i < _length; i++) str[i] = s.str[i];
   type = 1;
    }


    int get_length ()
    {
         cout << "Метод получения длины строки"<< endl;
         return _length  ;
    };

    void printLine()
    {
      if (type != 0)
      for (int i = 0; i < _length; i++) cout << str[i];
      else cout << " ";
    }


    String &operator=(const String &s)
     {
       cout << "String: перегрузка оператора =" << endl;

       type = s.type;
       _length = s._length;

       if (str != nullptr) delete[] str;

       str = new char[_length];

       for (int i = 0; i < _length; i++) str[i] = s.str[i];

       return *this;
     }

    String &operator=(const char *s)
     {
       cout << "String: перегрузка оператора =" << endl;

       int s_length;
       for (int s_length = 0; s[s_length]; s_length++)
       _length = s_length;

       if (str != nullptr) delete[] str;

       str = new char[_length];

       for (int i = 0; i < _length; i++) str[i] = s[i];

       return *this;
     }

    bool operator>(String *other)
      {

        cout << "String: перегрузка оператора >" << endl;

        return this->_length>other->_length;
      };



      char &operator[](int i) { return str[i]; }



      char getType() { return type; }

    ~String()
      {
        cout << "String: деструктор" << endl;
        if (str != nullptr) delete[] str;
      };


};


class IdentifierString  : public String
{
   int copyIndifer;
   public:
    IdentifierString() : String()
      {
        cout << "IdentifierString: конструктор без параметров" << endl;
        type = 2;

    }

    IdentifierString(const char *s)
     {
       cout << "IdentifierString: конструктор, принимающий в качестве параметра Си-строку" << endl;
       for (_length = 0; s[_length] != '\n'; _length++)
       str = new char[_length];

       if ((s[0] < 'a' || s[0] > 'z') && (s[0] < 'A' || s[0] > 'Z') && (s[0] != '_'))
       {
         cout << "IdentifierString: встречен недопустимый символ. Создана пустая строка"  << endl;
         type = 0;
         _length = 1;
         str = new char[_length];
         str[0] = '0';
         return;
       }

       for (_length = 1; s[_length] != '\n'; _length++)
       {
         if ((s[_length] < '0' || s[_length] > '9') && (s[_length] < 'a' || s[_length] > 'z') &&
             (s[_length] < 'A' || s[_length] > 'Z') && s[_length] != '_'&&s[_length]!='\n')
         {
           cout << "IdentifierString: встречен недопустимый символ. Создана пустая строка" << endl;
           type = 0;
           _length = 1;
           str = new char[_length];
           str[0] = '0';
           return;
         }
       }

       str = new char[_length];
       for (int i = 0; i < _length; i++) str[i] = s[i];
       type = 2;

     }

    IdentifierString(char c)
     {
       cout << "Kонструктор, принимающий в качестве параметра символ (char)" << endl;

       if (c!='\n' && (c < 'a' || c > 'z')&&(c < 'A' || c > 'Z')&&(c < '0' || c > '9') && c != '-' && c != '+')
       {
         cout << "Bстречен недопустимый символ. Создана пустая строка"  << endl;
        type = 0;
         _length = 1;
         str = new char[_length];
         str[0] = '0';
         return;
       }

       _length = 1;
       str = new char[_length];
       str[0] = c;
       type = 3;

     }

    IdentifierString(const IdentifierString &other)
      {
        copyIndifer++;
        cout << "IdentifierString: конструктор копирования отработал "<< copyIndifer << endl;

        _length = other._length;
        str = new char[_length];

        for (int i = 0; i < _length; i++) str[i] = other.str[i];
        type = 2;

      }

    void changeCase()
     {
       cout << "IdentifierString: перевод символов в верхний регистр" << endl;

       for (int i = 0; i < _length; i++)
       {
         if (str[i] > 96 && str[i] < 123) str[i] = str[i] - 32;
       }
     }

     bool  operator >(const IdentifierString &other)
     {
       cout << "IdentifierString: перегрузка оператора >" << endl;

         return  (_length > other._length)? true: false;

};


     IdentifierString &operator=(IdentifierString  &other)
       {
         cout << "DecimalString: перегрузка оператора =" << endl;

         if (str != nullptr) delete[] str;
       int length;
        for (length = 0; other.str[_length] != '\n'; length++)
         str = new char[length];

         for (int i = 0; i < length; i++) str[i] = other.str[i];
          *this = other;
         return *this;
       }

    IdentifierString &operator=(const char *s)
      {
        cout << "IdentifierString: перегрузка оператора =" << endl;

        int s_length;
        for (s_length = 0; s[s_length]; s_length++);
        _length = s_length;

        if (str != nullptr) delete[] str;

        str = new char[_length];

        for (int i = 0; i < _length; i++) str[i] = s[i];

        return *this;
      }

       char &operator[](int i) { return str[i]; }

};


class DecimalString : public String
{
int copyDemocal;
public:
  DecimalString() : String()
  {
    cout << "DecimalString: конструктор без параметров" << endl;
    type = 3;

  }

  DecimalString(const char *s)
  {
    cout << "DecimalString: конструктор, принимающий в качестве параметра Си-строку" << endl;
    for (_length = 0; s[_length] != '\n'; _length++)
    str = new char[_length];

    if ((s[0] < '0' || s[0] > '9') && (s[0] != '-') && (s[0] != '+'))
    {
      cout << "DecimalString: встречен недопустимый символ. Создана пустая строка" << endl;
      type = 0;
      _length = 1;
      str = new char[_length];
      str[0] = '0';
      return;
    }

    for (_length = 1; s[_length] != '\n' ; ++_length)
    {
      if ((s[_length] < '0' || s[_length] > '9'))
      {
        cout << "DecimalString: встречен недопустимый символ. Создана пустая строка" << endl;
        type = 0;
        _length = 1;
        str = new char[_length];
        str[0] = '0';
        return;
      }
    }

    str = new char[_length];
    for (int i = 0; i < _length; i++) str[i] = s[i];
    type = 3;
  }

  DecimalString(char c)
  {
    cout << "DecimalString: конструктор, принимающий в качестве параметра символ (char)"<< endl;

    if ((c < '0' || c > '9') && (c != '-') && (c != '+'))
    {
      cout << "DecimalString: встречен недопустимый символ. Создана пустая строка" << endl;
      _length = 1;
      str = new char[_length];
      str[0] = '0';
      return;
    }

    _length = 1;
    str = new char[_length];
    str[0] = c;
    type = 3;
  }



  DecimalString(const DecimalString &s)
    {
    copyDemocal++;
      cout << "DecimalString: конструктор копирования отработал"<< copyDemocal << endl;

      _length = s._length;
      str = new char[_length];

      for (int i = 0; i < _length; i++) str[i] = s.str[i];
      type = 3;

  }

  bool Definiction()
  {

      if (!this->type || atof(this->str) < 4294900000 && this->str[0] != '-')
          return true;
      else return false;
  };

  DecimalString &operator=(DecimalString  &other)
    {
      cout << "DecimalString: перегрузка оператора =" << endl;

    int length;
    for (length = 0; other.str[length] != '\n'; length++)
    _length = length;

    if (str != nullptr) delete[] str;
    str = new char[_length];

      for (int i = 0; i < _length; i++) str[i] = other.str[i];
      // *this = other;
      return *this;
    }

  DecimalString &operator=(const char *s)
   {
     cout << "DecimalString: перегрузка оператора =" << endl;

     int s_length;
     for (s_length = 0; s[s_length]; s_length++)


     if (str != nullptr) delete[] str;
     _length = s_length;
     str = new char[_length];

     for (int i = 0; i < _length; i++) str[i] = s[i];
     return *this;
   }

  bool  operator> (const DecimalString &other)
  {
    cout << "DecimalString: перегрузка оператора >" << endl;
    if (this->str[0] != '-' && other.str[0] == '-'  ) return true;
    if (this->str[0] == '-' && other.str[0] != '-'  ) return false;

    for(int i = 0; i<100 ;++i)
    {
        if (this->str[i] > other.str[i] && this->_length > other._length)  return(this->str[0] == '-' && other.str[0] == '-'  )? false : true ;
        if (this->str[i] < other.str[i] && this->_length < other._length )  return(this->str[0] == '-' && other.str[0] == '-'  )? true : false;
    }
  };

    char &operator[](int i) { return str[i]; }

 };

class Menu
{
 private:
  int _stringNumber = 0;
  String **_strArr = nullptr;

  int _input(const string &message)
  {
    int num;

    while (true)
    {
      char c;
      cout << message;
      cin >> num;
      c = getchar();

      if (cin.fail() || c != '\n')
      {
        cout << "Ошибка ввода!" << endl;
        cin.clear();
        cin.ignore(32767, '\n');
      }
      else
      {
        break;
      }
    }

    return num;
  }

  void _initStrings(void)
  {
    int choice, j;
    char *str = new char[100];

    while (true)
    {

      _stringNumber = _input("Введите количество строк, которые нужно создать: ");
      if (_stringNumber < 1)
      {
        cout << "Ошибка ввода!" << endl;

        continue;
      }

      _strArr = new String *[_stringNumber];
      if (!_strArr)
      {
        cout << "Ошибка выделения памяти!" << endl;
        _stringNumber = 0;

        continue;
      }

      for (int i = 0; i < _stringNumber; i++)
      {
        cout << endl << "Ввод строки " << i << ": ";
        for (j = 0; j < 100; j++)
        {
          str[j] = getchar();
          if (str[j] == '\n') break;

        }

        if (str[j] != '\n') while (getchar() != '\n') ;

        if (j == 0)
        {
          cout << "Вы ввели пустую строку!" << endl;

          continue;
        }

        cout << "Выберите тип строки:" << endl
             << "1. Cтрока" << endl
             << "2. Строка-идентификатор" << endl
             << "3. Десятичная строка" << endl;

        while (true)
        {
          choice = _input("Введите тип строки: ");
          if (choice < 1 || choice > 3)
            cout << "Неверный ввод!" << endl;
          else
            break;
        }

        switch (choice)
        {
          case 1:
            _strArr[i] = new String(str);
          case 2:
            _strArr[i] = new IdentifierString(str);
            break;
          case 3:
            _strArr[i] = new DecimalString(str);
            break;
        }

        if (_strArr[i]->get_length() == 0) continue;
      }

      break;
    }

    delete[] str;
  }

 public:
  int run(void)
  {
    int option, entered_lines = 0;
    bool test= true;

    while (true)
    {
      _initStrings();

      String *operand_1 = nullptr;
      String *operand_2 = nullptr;

      while (test)
      {

        cout << "1. Операции для строки" << endl
             << "2. Операции для строки-идентификатора" << endl
             << "3. Операции для десятичной строки" << endl
             << "4. Выбрать операнды" << endl
            // << "5. Вернуться в меню инициализации" << endl //Доделать
             << "6. Завершить выполнение программы" << endl;

        option = _input("Ввод: ");

        switch (option)
        {
          case 1:
          {
            if (operand_1 == nullptr)
            {
              cout << "Ошибка: операнд не задан" << endl;
              break;
            }
            cout << endl << "1. Получение длины строки" << endl;
                cout << "Длина строки равна " << operand_1->get_length() << endl;


            break;
          }

          case 2:
          {
            if (operand_1 == nullptr)
            {
              cout << "Ошибка: операнд не задан" << endl;
              break;
            }
            else if (operand_1->getType() != 2)
            {
              cout << "Ошибка: заданный операнд не является строкой-идентификатором"
                   << endl;
              break;
            }

            cout << endl << "1. Перевести все символы первого операнда в верхний регистр" << endl;
            cout << "2. Сравнить > первый операнд со вторым" << endl;
            cout << "3. Переписать первый операнд" << endl;

            while (true)
            {
              option = _input("Ввод: ");
              if (option < 1 || option > 3)
                cout << "Неверный ввод!" << endl;
              else
                break;
            }

            if (option == 1)
            {
              ((IdentifierString *)operand_1)->changeCase();
              cout << "Результат: ";
              operand_1->printLine();
              cout << endl;
            }
            else if (option == 2)
            {
              if (operand_2->getType() != 2)
              {
                cout << "Ошибка: второй операнд не является строкой-идентификатором " << endl;
                break;
              }
              else
              {

                cout << (*((IdentifierString *)operand_1) > *((IdentifierString *)operand_2) ? "Первый операнд больше второго":"Второй операнд больше первого")
                     << endl << endl;
              }
            }
              else if (option == 3)
              {
                if (operand_1->getType() != 2 && operand_1->getType() != 0)
                {
                  cout << "Ошибка: операнд не является строкой индификатором" << endl;
                  break;
                };
                char *s = new char[100];
                cout << "Ввeдите строку " << endl;
                for (int j = 0; j < 100; j++)
                {
                  s[j] = getchar();
                  if (s[j] == '\n') break;

                }

                String *sd = new IdentifierString(s);
                *operand_1 = *sd;
                delete sd;
                delete[] s;
            }
            break;
          }

          case 3:
          {
            if (operand_1 == nullptr)
            {
              cout << "Ошибка: операнд не задан" << endl;
              break;
            }
            else if (operand_1->getType() != 3 && operand_1->getType() != 0)
            {
              cout << "Ошибка: заданный операнд не является десятичной строкой" << endl;
              break;
            }

            cout << endl << "1. Сравнить > первый операнд со вторым" << endl;
            cout << "2. Можно ли первый операнд представить в unsingned long " << endl;
            cout << "3. Переписать первый операнд " << endl;
            while (true)
            {
              option = _input("Ввод: ");
              if (option < 1 || option > 3)
                cout << "Неверный ввод!" << endl;
              else
                break;
            }

            if (option == 1)
            {
              if (operand_2->getType() != 3 && operand_2->getType() != 0)
              {
                cout << "Ошибка: второй операнд не является десятичной строкой" << endl;
                break;
              }
              else
              {


                cout << endl << (*((DecimalString*)operand_1) > *((DecimalString*)operand_2) ? "Первый операнд больше второго":"Второй операнд больше первого")
                     << endl << endl;
              }
            }
            else if (option == 2)
            {
              if (operand_1->getType() != 3 && operand_1->getType() != 0)
              {
                cout << "Ошибка: операнд не является десятичной строкой" << endl;
                break;
              }
             cout << (((DecimalString *)operand_1)->Definiction()? "Операнд можно представить в формате unsigned long ":" Операнд нельзя представить в формате unsigned long")
                  << endl << endl;


            }
            else if (option == 3)
            {
              if (operand_1->getType() != 3 && operand_1->getType() != 0)
              {
                cout << "Ошибка: операнд не является десятичной строкой" << endl;
                break;
              };
             char *s = new char[100];
             cout << "Ввeдите строку " << endl;
             for (int j = 0; j < 100; j++)
             {
               s[j] = getchar();
               if (s[j] == '\n') break;

             }

             String *sd = new DecimalString(s);
             *operand_1 = *sd;
             delete sd;
             delete[] s;
            }
            break;
          }

          case 4:
          {
            cout << endl;
            for (int i = 0; i < _stringNumber; i++)
            {
              cout << i + 1 << ") ";
              if (_strArr[i]->getType() == 1)
                cout << "Строка: ";
              else if (_strArr[i]->getType() == 2)
                cout << "Строка-идентификатор: ";
              else if (_strArr[i]->getType() == 3){
                cout << "Десятичная строка: ";}
              else cout << "Пустая строка: ";
              _strArr[i]->printLine();
              cout << endl;
            }
            cout << endl;
            cout << "Выберите номер строки, которую вы хотите сделать первым операндом"<< endl;

            while (true)
            {
              option = _input("Введите номер строки: ");
              if (option < 1 || option > _stringNumber)
                cout << "Неверный ввод!" << endl;
              else
                break;
            }

            operand_1 = _strArr[option - 1];
            cout << "Первый операнд равен строке '";
            operand_1->printLine();
            cout << "'" << endl << endl;
            cout << "Выберите номер строки, которую вы хотите сделать вторым операндом"<< endl;

            while (true)
            {
              option = _input("Введите номер строки: ");
              if (option < 1 || option > _stringNumber)
                cout << "Неверный ввод!" << endl;
              else
                break;
            }

            operand_2 = _strArr[option - 1];
            cout << "Второй операнд равен строке '";
            operand_2->printLine();
            cout << "'" << endl;

            break;
          }

          case 5:
          {
            test = false;
            break;
          }

          case 6:
          {
            for (int i = 0; i < _stringNumber; i++)
            {
              if (_strArr[i] != nullptr) delete _strArr[i];
            }
            delete[] _strArr;
            return 0;
          }

          default:
            cout << "Ошибка: выбран несуществующий пункт меню" << endl;
            break;
        }

      }
    }
  }
};



int main()
{

    system ("chcp 65001");
    Menu().run();
    return 0;
}
