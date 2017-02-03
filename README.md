# Defusing-Bomb

Original description here: https://www.reddit.com/r/dailyprogrammer/comments/5emuuy/20161124_challenge_293_intermediate_defusing_the/

Program to simulate bomb defusal based on a set of rules. 

Rule set:
  You have to start with either with a white or a red wire.
  If you picked white wire you can either pick another white wire again or you can take an orange one.
  If you picked a red wire you have the choice between a black and red wire.
  When a second red wire is picked, you can start from rule one again.
  Back to the second rule, if you picked another white one you will have to pick a black or red one now
  When the red wire is picked, you again go to rule one.
  On the other hand if you then picked an orange wire, you can choose between green, orange and black.
  When you are at the point where you can choose between green, orange and black and you pick either green or orange you have to choose the other one and then the bomb is defused.
  If you ever pick a black wire you will be at the point where you have to choose between green, orange and black

Finite State Machine Representing Rules:
![alt tag](http://i.imgur.com/b0hoNrp.png)
