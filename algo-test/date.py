#!/usr/bin/env python
# -*- coding: utf-8 -*-
import sys
from Tkinter import *
from math import *

class Test(Frame):
  def __init__(self, parent):
    Frame.__init__(self, parent)
    self.grid()
    root.bind_all('<Control-c>', lambda i = 0:sys.exit(i))
    root.bind_all('<Control-d>', lambda i = 0:sys.exit(i))
    self.d = 256
    self.mg = 15
    self.pwrNE = 0
    self.pwrSE = 0
    self.pwrSW = 0
    self.pwrNW = 0
    self.pwrs = [self.pwrNE, self.pwrSE, self.pwrSW, self.pwrNW]
    self.algoNE = ''
    self.algoSE = ''
    self.algoSW = ''
    self.algoNW = ''
    self.algos = [self.algoNE, self.algoSE, self.algoSW, self.algoNW]
    self.ch3 = 0
    self.ch4 = 0
    self.indicate = 0
    self.dot = 0
    self.buildWrapper()
    self.buildMain()
  def makeWrapper(self):
    return Frame(self)
  def buildWrapper(self):
    self.inputWrapper = self.makeWrapper()
    self.inputWrapper.grid(row=0, column=0, rowspan=2)
    self.controlWrapper = self.makeWrapper()
    self.controlWrapper.grid(row=1, column=0, sticky = SW)
  def buildMain(self):
    self.buildInput()
    self.buildJoystick()
    self.buildControl()
    self.buildResult()
  def makeInputLbl(self, txt):
    return Label(self.inputWrapper, width=2, text=txt)
  def makeInputEnt(self):
    return Entry(self.inputWrapper, width = 67)
  def buildInput(self):
    self.lblNE = self.makeInputLbl('NE')
    self.lblSE = self.makeInputLbl('SE')
    self.lblSW = self.makeInputLbl('SW')
    self.lblNW = self.makeInputLbl('NW')
    self.lbls = (self.lblNE, self.lblSE, self.lblSW, self.lblNW)
    for l in range(len(self.lbls)):
      self.lbls[l].grid(row = l, column = 0)
    self.entNE = self.makeInputEnt()
    self.entSE = self.makeInputEnt()
    self.entSW = self.makeInputEnt()
    self.entNW = self.makeInputEnt()
    self.ents = (self.entNE, self.entSE, self.entSW, self.entNW)
    for e in range(len(self.ents)):
      self.ents[e].grid(row = e, column = 1)
    self.evalButton = Button(self.inputWrapper, text='EVAL', padx=0, pady=35,
                             command = self.evalAlgos)
    self.evalButton.grid(row = 0, column = 2, rowspan = 4)
  def buildJoystick(self):
    self.Joystic = Canvas(self.inputWrapper,width=2*self.d+21,height=self.d+10)
    self.Joystic.configure(cursor = 'crosshair')
    self.Joystic.bind('<Button-1>', self.trackCursor)
    self.Joystic.bind('<space>', self.trackCursor)
    self.Joystic.grid(row = 4, column = 0, columnspan = 3)
    self.Joystic.create_oval(5,5,5+self.d,5+self.d)
    self.Joystic.create_line(0, 5+self.d/2, 9+self.d,5+self.d/2)
    self.Joystic.create_line(5+self.d/2, 0, 5+self.d/2, self.d+10)
    self.dot = self.Joystic.create_oval(132, 132, 134, 134, fill = 'black')
  def buildControl(self):
    self.runButton = Button(self.controlWrapper, text="RUN", padx=0,pady=0,
                            command = self.run)
    self.runButton.pack()
    self.stopButton = Button(self.controlWrapper, text="STOP", padx=0,pady=0,
                             command = self.stopit)
    self.stopButton.pack()
  def buildResult(self):
    self.Joystic.create_polygon(15+7*self.d/4, 5,
                                15+2*self.d,   5+self.d/4,
                                15+2*self.d,   5+3*self.d/4,
                                15+7*self.d/4, 5+self.d,
                                15+5*self.d/4, 5+self.d,
                                15+self.d,     5+3*self.d/4,
                                15+self.d,     5+self.d/4,
                                15+5*self.d/4, 5,
                                fill='#dcdcdc', width=3, outline='black')
    self.txtPwrNE = self.Joystic.create_text(15+2*self.d-self.mg, 5+self.mg,
                                             width=4, text=str(self.pwrNE))
    self.txtPwrSE = self.Joystic.create_text(15+2*self.d-self.mg,
                                             5+self.d-self.mg, width=4,
                                             text=str(self.pwrSE))
    self.txtPwrSW = self.Joystic.create_text(15+self.d+self.mg,
                                             5+self.d-self.mg, width=4,
                                             text=str(self.pwrSW))
    self.txtPwrNW = self.Joystic.create_text(15+self.d+self.mg,
                                             5+self.mg, width=4,
                                             text=str(self.pwrNW))
    self.txtPwrs = (self.txtPwrNE, self.txtPwrSE, self.txtPwrSW, self.txtPwrNW)
  def getAlgos(self):
    for i in range(4):
      self.algos[i] = self.ents[i].get()
  def evalAlgos(self):
    self.indicate = self.Joystic.create_text(20,10,text = '')
    self.getAlgos()
    try:
      for i in range(4):
        self.pwrs[i] = eval(self.algos[i])
    except NameError or SyntaxError:
      self.Joystic.itemconfigure(self.indicate, text = 'ERROR!')
  def updatePwrText(self):
    [self.Joystic.itemconfigure(self.txtPwrs[i], text = str(self.pwrs[i])) \
    for i in range(4)]
  def trackCursor(self, event):
    x,y = event.x, event.y
    rng = range(-128, 128)
    if x-133 in rng and 133-y in rng and hyp(x-133, 133-y) in rng:
      self.Joystic.delete(self.dot)
      self.dot = self.Joystic.create_oval(x-1, y-1, x+1, y+1, fill = 'black')
      return x-133, 133-y
  def run(self):
    self.stop = False
    while not self.stop:
      self.ch4, self.ch3 = self.trackCursor()
  def stopit(self):
    self.stop = True


def hyp(x, y):
  return ceil((x*x+y*y)**.5)
if __name__ == "__main__":
  root = Tk()
  test = Test(root)
  root.mainloop()
