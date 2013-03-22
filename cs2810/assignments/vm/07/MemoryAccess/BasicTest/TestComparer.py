def main():
    fin1 = open("BasicTest.asm")
    fin2 = open("BasicTestCorrect.asm")

    fin1 = fin1.readlines()
    fin2 = fin2.readlines()

    i = len(fin1)
    j = len(fin2)
    if j < i:
        i = j

    for i in range(i):
        if fin1[i] != fin2[i]:
            print fin1[i], fin2[i], "Line %s" % i

main()
    
