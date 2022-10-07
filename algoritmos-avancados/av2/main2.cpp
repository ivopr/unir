#include <iostream>
#include <vector>
#include <algorithm>

/**
 * @brief Avaliação 2 - Algoritmos Avançados
 * @authors Ivo Vieira (201910633), Murilo Fuza (201911623)
 */

using namespace std;

void execute(vector<int> start, vector<int> end, vector<int> weights, int taskNumber) {
  if (taskNumber == 0) {
    return;
  }

  vector<int> tasks[taskNumber];
  int sum[taskNumber];

  for (int i = 0; i < taskNumber; i++) {
    sum[i] = 0;

    for (int j = 0; j < i; j++) {
      if (end.at(j) <= start.at(i) && sum[i] < sum[j]) {
        tasks[i] = tasks[j];
        sum[i] = sum[j];
      }
    }

    tasks[i].push_back(i);
    sum[i] += weights.at(i);
  }

  int pos = 0;
  for (int i = 1; i < taskNumber; i++) {
    if (sum[i] > sum[pos]) {
      pos = i;
    }
  }

  cout << sum[pos] << "\n";
  for (int i : tasks[pos]) {
    cout << i + 1 << " ";
  }
  cout << "\n";
}

int main() {
  int taskNumber;
  vector<int> startTimes, endTimes, weights;

  cin >> taskNumber;

  for (int i = 0; i <= 2; i++) {
    for (int j = 0; j < taskNumber; j++) {
      int aux;
      cin >> aux;
      if (i == 0) {
        startTimes.push_back(aux);
      } else if (i == 1) {
        endTimes.push_back(aux);
      } else {
        weights.push_back(aux);
      }
    }
  }

  execute(startTimes, endTimes, weights, taskNumber);

  return 0;
}