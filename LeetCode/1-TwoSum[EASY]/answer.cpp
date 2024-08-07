#include <iostream>
#include <vector>
#include <unordered_map>
#include <sstream>
#include <string>

using namespace std;

vector <int> twoSum (const vector <int> &nums, int target) {
    unordered_map <int, int> hash;

    for (int i=0; i < nums.size(); i++){
        int numberToFind = target - nums[i];

        if (hash.find(numberToFind) != hash.end()) {
            return {
                hash[numberToFind], i
            };
        }

        hash[nums[i]] = i;
    }
    return {};
}

int main () {
    string input;
    getline(cin, input);

    //parse the input
    size_t nums_start = input.find('[');
    size_t nums_end = input.find(']');
    string nums_str = input.substr(nums_start + 1, nums_end - nums_start - 1);

    vector <int> nums;
    stringstream ss(nums_str);
    string temp;
    while (getline(ss, temp, ',')) {
        nums.push_back(stoi(temp));
    }

    size_t target_pos = input.find("target = ");
    int target = stoi(input.substr(target_pos + 9));


    vector<int> result = twoSum(nums, target);

    if (!result.empty()) {
        cout << "[" << result[0] << "," << result[1] << "]" << endl;
    } else {
        cout << "No solution found!" << endl;
    }
    
}