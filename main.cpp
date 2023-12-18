#include <iostream>
#include <sstream>

using namespace std;

/**
 * @brief - метод, возвращающий заполненный пользователем массив.
 * @param size_ - размер массива.
 * @return - заполненный массив.
 */
int* InputArray(const size_t size_);

/**
 * @brief - вывод массива на консоль.
 * @param array - массив.
 * @param size_ - размер массива.
 */
string ToString(const int* array, const size_t size_);


/**
 * @brief - умножение на число.
 * @param array - массив.
  * @param size_ - размер массива.
  * @return - массив, помноженный на множитель.
 */
int* MultiplySix(int* array, const size_t size_);

/**
 * @brief - ввод и проверка на корректное число элементов массива
 * @param message - вывод определённой фразы при выполнении
 * @param size - размер массива
 */
size_t GetSize(const std::string& message);

int main()
{
  try{
    size_t sizeArr = GetSize("Введите размер массива: "), size = sizeArr;
   
    int* NewArray = InputArray(size);
    
      cout <<"Введенный массив: " << ToString(NewArray, size);

      MultiplySix(NewArray,size);

      cout <<"Результат: " << ToString(NewArray, size);

      if (NewArray != nullptr)
    {
       delete[] NewArray;
       NewArray = nullptr;
    }

  return 0;
}

size_t GetSize(const std::string& message)
{
    int size = -1;
    std::cout << message;
    std::cin >> size;

    if (size <= 0)
    {
        throw std::out_of_range("Неправильный размер. Значение должно быть больше или равно нулю.");
    }

    return static_cast<size_t>(size);
}

int* InputArray(const size_t size_){

  int* array = new int[size_];

  cout<<"Введите данные в массив\n";

  for (size_t index = 0 ; index < size_; index++){
      cin >> array[index];
    }

  return array;
}

string ToString(const int* array, const size_t size_)
{
  std::stringstream buffer{};

  for(size_t index = 0;index < size_ ;index++){
    buffer << array[index] << " ";
  }
  buffer << "\n";

  return buffer.str();  
}

int* MultiplySix(int* array, const size_t size_)
{
  for (size_t index = 0; index < size_; index++)
  {
    array[index] = array[index]*6;
  }
  return array;
}
