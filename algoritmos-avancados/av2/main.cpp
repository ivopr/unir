#include <iostream>
#include <vector>

int main() {
  int taskNumber, startTime;
  std::vector<int> startTimes, endTimes, weights, resPos, rsPos;

  std::cin >> taskNumber;

  for (int i = 0; i <= 2; i++) {
    for (int j = 0; j < taskNumber; j++) {
      int aux;
      std::cin >> aux;
      if (i == 0) {
        startTimes.push_back(aux);
      } else if (i == 1) {
        endTimes.push_back(aux);
      } else {
        weights.push_back(aux);
      }
    }
  }

  int jh = taskNumber - 1;
  int res = 0;
  while (jh >= 0) {
    int si = startTimes.at(jh);
    std::cout << si << '\n';

    for (int k = jh - 1; jh >= 0; jh--) {
      int ei = endTimes.at(k);

      if (si <= ei) {
        rsPos.push_back(k + 1);
        jh = k;
        res += weights.at(k);
        break;
      } else {
        jh--;
      }
    }
  }

  // int i = startTime;
  // int res = weights.at(startTime);
  // while (i < taskNumber) {
  //   // std::cout << "i: " << i << "\n";
  //   int fi = endTimes.at(i);

  //   for (int j = i + 1; j < taskNumber; j++) {
  //     int si = startTimes.at(j);

  //     // std::cout << si << " " << fi << "\n"; 
      
  //     if (si >= fi) {
  //       resPos.push_back(j + 1);
  //       res += weights.at(j);
  //       i = j;
  //       break;
  //     } else {
  //       i += 1;
  //     }
  //   }

  //   // std::cout << "\n";
  //   if (i == taskNumber - 1) {
  //     break;
  //   }
  // }

  std::cout << res << "\n";
  for(auto it : rsPos) {
    std::cout << it << " ";
    res += weights.at(it - 1);
  }

  return EXIT_SUCCESS;
}