/*Тип аргументов: double unsingned char
Поиск наименьшего неотрицательного элемента
АТД Стек.
*/

#include <iostream>
#include <string>


using namespace std;

template <class T>
class _Vector
{public:
 T  min = ((sizeof(T)<2)? 250:INT_MAX);
 private:
  int _top = 0;
 T *_data = nullptr;
  int _maxlength = 0;

 public:
  _Vector(int n)
  {
 _maxlength = n;
 _data = new T[_maxlength];
 _top = -1;

  }

   bool isEmpty()
  {
    if (_top < 0)
      return true;
    else
      return false;
  }
   bool isFull()
  {
    if (_top < 0)
      return false;
    else
      return true;
  }
   T top()  { return _data[_top]; }

   T pop_back()  { return _data[_top--]; }

   int push_back(T data)
  {
    if (_top == _maxlength - 1) return 0;
    if (data > 0 && data < min) min = data;
    _data[++_top] = data;
    return 1;
  }


   T getMin() { return min; }

   ~_Vector()  { delete[] _data; }
};
using namespace std;


template <class T>
class IStack
{
 public:
  bool virtual isEmpty() = 0;
  bool virtual isFull() = 0;
  virtual T top() = 0;
  virtual T pop() = 0;
  virtual int push(T) = 0;
  virtual int getType() = 0;
  virtual T getMin() = 0;
  virtual ~IStack(){};
};


template <class T>
class StackVector : public IStack<T>
{public:
   T min = 250;
 private:
  int _top = 0;
 T *_data = nullptr;
  int _maxlength = 0;

 public:
  StackVector(int n)
  {
 _maxlength = n;
 _data = new T[_maxlength];
 _top = -1;
  }

  virtual bool isEmpty() override
  {
    if (_top < 0)
      return true;
    else
      return false;
  }
  virtual bool isFull() override
  {
    if (_top == _maxlength - 1)
      return true;
    else
      return false;
  }
  virtual T top() override { return _data[_top]; }

  virtual T pop() override { return _data[_top--]; }

  virtual int push(T data) override
  {
    if (_top == _maxlength - 1) return 0;
    if (data > 0 && data < min) min = data;
    _data[++_top] = data;
    return 1;
  }

  virtual int getType() override { return 0; }

  virtual T getMin() override { return min; }

  virtual ~StackVector() override { delete[] _data; }
};

template <class T>
class StackList : public IStack<T>
{
public:
   T min = 250;
 private:
  typedef struct node
  {
    T data;
    node *next;
  } * pnode;

  pnode pstack = nullptr;
  bool _ful = true;
 public:
  StackList() { pstack = NULL; }

  virtual bool isEmpty() override
  {
    if (pstack == nullptr)
      return true;
    else
      return false;
  }
  virtual bool isFull() override
  {

    if (!_ful)
        return true;
      else
        return false;
  }

  virtual T top() override { return pstack->data; }

  virtual T pop() override
  {
    pnode del = pstack;
    T temp = pstack->data;
    pstack = pstack->next;
    delete del;
    _ful = true;
    return temp;
  }

  virtual int push(T data) override
  {
    if (pnode ins = new struct node)
    {
        if (data > 0 && data < min) min = data;
        ins->data = data;
        ins->next = pstack;
        pstack = ins;

   }
    else _ful = false;
        return 1;
  }

  virtual int getType() override { return 1; }

  virtual T getMin() override { return min; }


  virtual ~StackList() override
  {
    pnode temp;

    while (pstack)
    {
      temp = pstack;
      pstack = pstack->next;
      delete temp;
    }
  }
};

template <class T>
IStack<T> *stack = nullptr;

template <class T>
_Vector<T> *arr = nullptr;

class Menu final
{
 private:
  int _stackType = -1;
  int _elementCount = -1;

  template <typename T>
  T _input(const string &message)
  {
    T num;

    while (true)
    {
      unsigned char c;
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

  template <class T>
  void _test(void)
  {
    int input = 0;


    while (true)
    {
      cout << "0. Добавить элемент" << endl
           << "1. Проверка пустоты" << endl
           << "2. Проверка переполнености" << endl
           << "3. Удалить элемент" << endl
           << "4. Минимальный положительный элемент стека" << endl
           << "5. Печать стека" << endl
           << "6. Возврат в начальное меню" << endl
           << "7. Введите массив" << endl;

      input = _input<int>("Ввод: ");

      switch (input)
      {
        case 0:
        {
          if (_stackType == 1)
          {
            stack<T>->push(_input<double>("Введите число: "));
          }
          else if (_stackType == 2)
          {
            short int num;
            while (true)
            {
              num = _input<unsigned char>("Введите символ\\число: ");
              if (num < 0 || num > 255)
              {
                cout << "Ошибка ввода!" << endl;
              }
              else
              {
                stack<T>->push((unsigned char)num);
                break;
              }
            }
          }
          break;
        }
      case 1:
      {
        cout << ((stack<T>->isEmpty())? "Пустой":"Не пуст")<<endl;
        break;
      }
      case 2:
      {
        cout << ((stack<T>->isFull())? "Переполнен":"Не Переполнен")<<endl;
        break;
      }
        case 3:
        {

         if (!stack<T>->isEmpty()) stack<T>->pop();
          break;
        }
        case 4:
        {

          cout << "Результат: " << static_cast<T>(stack<T>->getMin()) << endl;
          cout << endl;
          break;
        }
        case 5:
        {
          cout << "Содержимое стека: " << endl;

          if (_stackType == 1)
            _print(stack<double>);
          else if (_stackType == 2)
            _print(stack<unsigned char>);
          cout << endl;
          break;
        }
        case 6:
        {
          delete stack<T>;
          stack<T> = nullptr;
          return;
        }
      case 7:
      {    
          while (true)
          {
            cout << "Выберите пункт меню:" << endl
                 << "1. Массив с типом double" << endl
                 << "2. Массив с типом unsigned char" << endl
                 << "0. Выход." << endl;

            input = _input<int>("Ввод: ");
            _elementCount = _input<int>("Введите количество элементов массива: ");
            _stackType = input;
            switch (input)
            {

            case 1:
                arr<double> = new _Vector<double>(_elementCount);
                         break;


            case 2:
                arr<unsigned char> = new _Vector<unsigned char>(_elementCount);
                      break;


                    default:
                      cout << "Ошибка ввода!" << endl;
                      continue;

                  break;
           }
                while (true)
                {
                    cout << "0. Добавить элемент" << endl
                         << "1. Проверка переполнености" << endl
                         << "2. Проверка пустоты" << endl
                         << "3. Удалить элемент" << endl
                         << "4. Минимальный положительный элемент стека" << endl
                         << "5. Печать стека" << endl
                         << "6. Вернуться в начальное меню"<<endl;

                input = _input<int>("Ввод: ");

                switch (input)
                {
                  case 0:
                  {
                    if (_stackType == 1)
                    {
                      arr<T>->push_back(_input<double>("Введите число: "));
                    }
                    else if (_stackType == 2)
                    {
                      short int num;
                      while (true)
                      {
                        num = _input<unsigned char>("Введите символ\\число: ");
                        if (num < 0 || num > 255)
                        {
                          cout << "Ошибка ввода!" << endl;
                        }
                        else
                        {
                          arr<T>->push_back((unsigned char)num);
                          break;
                        }
                      }
                    }
                    break;
                  }
                case 1:
                {
                  cout << ((arr<T>->isEmpty())? "Пустой":"Не пуст");
                  break;
                }
                case 2:
                {
                  cout << ((arr<T>->isFull())? "Переполнен":"Не Переполнен");
                  break;
                }
                  case 3:
                  {
                    arr<T>->pop_back();
                    break;
                  }
                  case 4:
                  {

                    cout << "Результат: " << static_cast<T>(arr<T>->getMin()) << endl;
                    cout << endl;
                    break;
                  }
                  case 5:
                  {
                    cout << "Содержимое стека: " << endl;

                    if (_stackType == 1)
                      _print_arr(arr<double>);
                    else if (_stackType == 2)
                      _print_arr(arr<unsigned char>);
                    cout << endl;
                    break;
                   }
                case 6:
                {
                    delete arr<T>;
                    arr<T> = nullptr;
                    return;

                  }
                default:
                  cout << "Ошибка ввода!" << endl;
             }
          };

       }
          break;
        }

        default:
          cout << "Ошибка ввода!" << endl;
      }
    }
  }



  template <class T>
  void _print(IStack<T> *stack)
  {
    if (!stack->isEmpty())
    {
      T x = stack->top();
      stack->pop();

      _print(stack);
      if (sizeof (T)<2) cout << (double)x << '-';
      cout << (T)x << ' ';
      stack->push(x);
    }
  }

  template <class T>
  void _print_arr(_Vector<T> *arr)
  {
    if (!arr->isEmpty())
    {
      T x = arr->top();
      arr->pop_back();

      _print_arr(arr);
      if (sizeof (T)<2) cout << (double)x << '-';
      cout << (T)x << ' ';
      arr->push_back(x);
    }
  }


 public:
  int run(void)
  {
    int input = 0;
    while (true)
    {
      cout << "Выберите пункт меню:" << endl
           << "1. Стек с типом double" << endl
           << "2. Стек с типом unsigned char" << endl
           << "0. Выход." << endl;

      input = _input<int>("Ввод: ");

      _stackType = input;
      switch (input)
      {
        case 1:
        case 2:
          while (true)
          {
            cout << "Выберите пункт меню:" << endl
                 << "1. Стек с помощью связной структуры хранения." << endl
                 << "2. Стек с помощью векторной структуры хранения." << endl;

            input = _input<int>("Ввод: ");

            switch (input)
            {
              case 1:
                if (_stackType == 1)
                    stack<double> = new StackList<double>();
                else if (_stackType == 2)
                  stack<unsigned char> = new StackList<unsigned char>();
                else
                  return -1;

                break;
              case 2:
                _elementCount = _input<int>("Введите количество элементов cтека: ");
                if (_stackType == 1)
                  stack<double> = new StackVector<double>(_elementCount);
                else if (_stackType == 2)
                  stack<unsigned char> = new StackVector<unsigned char>(_elementCount);
                else
                  return -1;

                break;

              default:
                cout << "Ошибка ввода!" << endl;
                continue;
            }
            break;
          }
          break;
        case 0:
          return 0;
        default:
          cout << "Ошибка ввода!" << endl;
      }

      if (_stackType == 1)
        _test<double>();
      else if (_stackType == 2)
        _test<unsigned char>();
    }
  }
};

int main() {
      system ("chcp 65001");
    Menu().run();
             return 0 ;}

