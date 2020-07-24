from ROOT import *


old_file = TFile('Data_2018MagDown_file1_trimmed_copy.root')
background_tree = old_file.Get("BackgroundTree")

new_file = TFile('MC2018_MagDown_21513012_copy.root', 'update')
new_background_tree = background_tree.CloneTree()

new_file.Write()


