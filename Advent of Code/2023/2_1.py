with open("in.txt", "r") as f:
    lines = f.readlines()

#Part 1
sum=0
powersum = 0
for line in lines:
    _gameno, _input = line.strip().split(":")
    game,gameno = _gameno.split()
    inputs = _input.split(";")
    r,g,b = 0,0,0
    for input in inputs:
    
        colors = input.split(",")
        for _color in colors:
            count,color = _color.strip().split()
            if color == "red": r = max(r,int(count))
            if color == "green": g = max(g,int(count))
            if color == "blue": b = max(b,int(count))
            #print(gameno,count,color)

    print(">>>",r,g,b)
    power = r*g*b
    powersum += power
    if r <= 12 and g <=13 and b <=14:
        sum += int(gameno)
        print(gameno, sum, line)

print("Part1:",sum, "Part2:",powersum)