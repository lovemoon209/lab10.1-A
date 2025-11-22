/*
Рівень А). Сформувати масив структур, що містять інформацію про: прізвище
студента, курс, спеціальність (для представлення спеціальності використовувати
переліки, а для представлення курсу – цілі числа) та оцінки з фізики,
математики, інформатики.
 */

/*
Рівень А) – сім клітинок: (1) – порядковий номер студента у групі, (2) –
прізвище, (3) – курс, (4) – спеціальність, оцінки з (5) – фізики, (6) –
математики, (7) – інформатики;
*/

/*
Варіант 14.
1. Обчислити кількість кожної з оцінок «5», «4», «3» з програмування.
2. Обчислити процент студентів, які отримали і з фізики і з математики оцінки
«4» або «5».
*/
#include "lab10astud.h"
#include <iomanip>
#include <iostream>
#include <string>
using namespace std;
using namespace nsStud;

int main() {
  Student s[] = {
      {1, "Lunga", I, RI, 5, 5, 5},      {2, "Kuzma", II, VR, 5, 4, 3},
      {3, "Petrenko", III, CS, 4, 4, 4}, {4, "Sidorov", IV, KS, 3, 5, 4},
      {5, "Ivanov", V, RI, 4, 3, 5},     {6, "Smirnov", II, CS, 5, 5, 5},
      {7, "Kovalenko", III, VR, 3, 4, 3}};

  int n = sizeof(s) / sizeof(s[0]);

  cout << left << setw(5) << "№" << setw(20) << "Прізвище" << setw(16) << "Курс"
       << setw(10) << "Спец." << setw(15) << "Фізика" << setw(20) << "Математ."
       << setw(10) << "Інформ." << endl;

  cout << string(65, '-') << endl;

  for (int i = 0; i < n; i++) {
    cout << left << setw(5) << s[i].nom << setw(12) << s[i].prizv << setw(12)
         << s[i].kurs << setw(8) << specToStr(s[i].special) << setw(10)
         << s[i].phys << setw(12) << s[i].math << setw(12) << s[i].iform
         << endl;
  }

  int count5 = 0, count4 = 0, count3 = 0;
  for (int i = 0; i < n; i++) {
    if (s[i].iform == 5)
      count5++;
    else if (s[i].iform == 4)
      count4++;
    else if (s[i].iform == 3)
      count3++;
  }

  cout << "Кількість оцінок 5: " << count5 << endl;
  cout << "Кількість оцінок 4: " << count4 << endl;
  cout << "Кількість оцінок 3: " << count3 << endl;

  int count4or5 = 0;
  for (int i = 0; i < n; i++) {
    if ((s[i].phys == 4 && s[i].math == 5) ||
        (s[i].math == 4 && s[i].phys == 5)) {
      count4or5++;
    }
  }

  cout << "Процент студентів з оцінками 4 та 5 з фізики та математики: "
       << (count4or5 * 100.0 / n) << "%" << endl;

  return 0;
}
 
