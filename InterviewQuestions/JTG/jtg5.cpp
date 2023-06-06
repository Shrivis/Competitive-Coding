void printAnagramAndChanges(string str1, string str2) {
    int countx[26] = {0}, county[26] = {0}, ctrx[26] = {0}, ctry[26] = {0};
    int change = 0;
    int l = str1.size();
    for (int i = 0; i < l; i++) {
        countx[str1[i] - 'A']++;
        county[str2[i] - 'A']++;
    }
    for (int i = 0; i < 26; i++) {
        if (countx[i] > county[i])
            ctrx[i] += (countx[i] - county[i]);
        else if (countx[i] < county[i])
            ctry[i] += (county[i] - countx[i]);
        change += abs(county[i] - countx[i]);
    }
    for (int i = 0; i < l; i++) {
        if (ctrx[str1[i] - 'A'] == 0) continue;
        int j;
        for (j = 0; j < 26; j++)
            if ((ctry[j]) > 0) break;
        if (countx[str1[i] - 'A'] == ctrx[str1[i] - 'A'] || str1[i] - 'A' > j) {
            countx[str1[i] - 'A']--;
            ctrx[str1[i] - 'A']--;
            ctry[j]--;
            str1[i] = 'A' + j;
        } else countx[str1[i] - 'A']--;
    }
    return change/2;
}