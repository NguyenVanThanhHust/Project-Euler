#include <iostream>
#include <deque>
#include <vector>

using namespace std;

int find_pos(int number, deque<vector<int>> result)
{
    int rs = result.size();
    if (number < result.at(0).at(0))
    {
        return 0;
    }
    else if (number > result[rs-1][rs-1])
    {
        return rs;
    }
    else
    {
        int k = 0;
        for (size_t i = 0; i < rs; i++)
        {
            if (number > result[i][i] && number < result[i + 1][i + 1])
            {
                k = i + 1;
                break;
            }
        }
        return k;
    }
}

int main()
{
    vector<int> input = { 0, 8,4,12,2,10,6,14,1,9,5,13,3,11,7,15 };
    int input_size = input.size();
    vector<int> curr_vec;
    curr_vec.push_back(input[0]);
    deque<vector<int>> result;
    result.push_back(curr_vec);
    for (size_t i = 1; i < input_size; i++)
    {

        int pos = find_pos(input[i], result);
        if (pos == 0)
        {
            curr_vec = result[0];
            curr_vec.pop_back();
            curr_vec.push_back(input[i]);
            result.pop_front();
            result.push_front(curr_vec);
        }
        else if (pos == result.size())
        {
            curr_vec = result[result.size() - 1];
            curr_vec.push_back(input[i]);
            result.push_back(curr_vec);
        }
        else
        {
            curr_vec = result[pos - 1];
            curr_vec.push_back(input[i]);
            result.erase(result.begin() + pos);
            std::deque<vector<int>>::iterator it = result.begin();
            for (size_t j = 0; j < pos; j++)
            {
                it++;
            }
            it = result.insert(it, curr_vec);
            //result.insert(result.begin + pos, it);
        }
    }
    
    int k = result.size();
    for (size_t i = 0; i < k; i++)
    {
        cout << result[k - 1][i] << " ";
    }
    std::cin.get();

}