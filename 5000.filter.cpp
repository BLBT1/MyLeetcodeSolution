//file A {a:1, b:2, c:3, d:100, k:1024, w 520}
/*
* filter {
* a: {cond: 'a = 2'}
* b: {cond : 'c = 4'}
* d :{cond: 'c' = 3'}
* k: {cond : 'd = 100'}
* }
*
*
*/
/// output:{d:100, k:1024}
//'a = 2'
// char[] arr = a, =, 2
//arr[2] 2 -> parseToInt

unordered_map<char, int> filter(unordered_map<char, int> &file,
                                unordered_map<char, string> &filter)
{
    unordered_map<char, int> res;
    for (auto &f : filter)
    {
        string cond = f.second;
        // assume space is enforce input
        stringstream(cond) ss;
        string charString;
        string opt;
        string number;
        ss >> charString;
        ss >> opt;
        ss >> number;
        char cond_char = charString[0];
        int cond_num = stoi(number);
        if (file.find(cond_char) != file.end())
        {
            if (cond_num == file[cond_char])
                if (file.find(f.first) != file.end())
                {
                    res[f.first] = file[f.first];
                }
        }
    } //for

    return res;
}