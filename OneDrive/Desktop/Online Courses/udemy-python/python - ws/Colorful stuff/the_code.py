from turtle import *
file=open('color_dictionary.txt','r')
color_dict={}

#store each line of the file in a list
lst=file.read().splitlines()
for i in lst:
    
    #split each line with ' : ', so we can separate keys and values
    (key,val)=i.split(' : ')
    print(key,val)
    
    #add the value to the respective key in the dictionary
    color_dict[key]=val
print(color_dict)
screen=Screen()
screen.setup(600,600)
screen.bgcolor(color_dict['light pink'])
color(color_dict['grey'])
style=('Arial',40,'bold')
write('Hello',font=style,align='center')
penup()
right(90)
forward(40)
pendown()
color(color_dict['cherry'])
screen.delay(3000)
write('world',font=style,align='center')
screen.clear()
screen.bgcolor('light blue')
color(color_dict['grey'])
dot(600)
color(color_dict['cherry'])
style=('Arial',20,'bold')
left(90)
write('Do not\ncomare yourself with anyone\nin this world,\nif you do so\nyou are\nINSULTING YOURSELF',font=style,align='center')
#mainloop() keeps the window open
screen.mainloop()