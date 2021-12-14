# this program is a simple config file reader

lst = []

with open('example.conf') as f:
    lst = f.readlines()

for op in lst:
    args = op.split()
    key = args[0]
    value = args[1]
    print(f'key={key} value={value}')
    if key == 'area':
        # do something with area
        print('The area is {:05.2f}'.format(float(value)))
