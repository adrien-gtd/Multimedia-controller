##########################################
#
#  Exemple de Makefile
#  Eric Lecolinet - Reda Dehak - Telecom ParisTech 2015
#  INF224 - TP Java/Swing - http://www.telecom-paristech.fr/~elc/inf224
#
##########################################

#
# Nom du programme (doit correspondre au fichier qui contient main())
#
PROG = Main

#
# Fichiers sources .java
#
SOURCES = $(shell find . -name '*.java')

#
# Compilateur Java
#
JC = javac

#
# Options du compilateur Java
#
JFLAGS = -g -d ./bin	


##########################################
#
# Regles de construction/destruction des .class et de l'executable
#
 
all: classes

run: all
	java -cp ./bin ${PROG}

classes: $(SOURCES:.java=.class)

clean:
	-@$(RM) ./bin/*.class 1>/dev/null 2>&1
  
tar:
	tar cvf ${PROG}.tar.gz ${SOURCES}


###########################################
#
# Regles implicites
#

.SUFFIXES: .java .class

.java.class:
	$(JC) $(JFLAGS) $*.java
