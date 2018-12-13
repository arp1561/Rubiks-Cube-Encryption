import random
def selectRandom():
    universalSet = ['a','b','c','d','e','f','g','h','i','j','k','l','m','n','o','p','q','r','s','t','u','v','w','x','y','z',' ']
    secure_random = random.SystemRandom()
    return secure_random.choice(universalSet)



def main():
    fp = open("plainTextRandom.txt","wb")
    mainSet = []
    tempStr = ""
    while len(mainSet)<=100000:
        print len(mainSet)
        tempStr=""
        while len(tempStr)<=99:
            tempStr+=selectRandom()
        mainSet.append(tempStr)
        fp.write(tempStr+'\n')
if __name__=='__main__':
    main()


