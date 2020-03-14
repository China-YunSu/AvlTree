@echo off 
cl  -c showError.c 
cl  -c userType.c
cl -c AvlTree.c
cl -c AvlTreeComponent.c


cl test.c  showError.obj AvlTreeComponent.obj userType.obj AvlTree.obj