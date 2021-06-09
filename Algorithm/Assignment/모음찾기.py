def count_vowel(word:str)->int:
    """
    모음 찾기
    Time : O(N)
    Space : O(1)
    """
    lis = ['a','e','i','o','u']
    cnt = 0
    for a in word:
        if a in lis:
            cnt += 1
    return cnt

if __name__ == '__main__':
    word = "abracadabra "
    print(count_vowel(word))