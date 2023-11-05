#Makefile made by Coder 1 
CC = gcc
CFLAGS = -Wall -I/usr/include/ -I.
LDFLAGS = -lncurses 
OBJ = game.c gameDyn.c

all: printLogo gameDyn
	
printLogo:
	$(info  %%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%)
	$(info  %%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%)
	$(info %   .::::::::      :::       :::   :::   :::::::::: %)
	$(info %   :+:    :+:   :+: :+:    :+:+: :+:+:  :+:        %)
	$(info %   +:+         +:+   +:+  +:+ +:+:+ +:+ +:+        %)
	$(info %   :#:        +#++:++#++: +#+  +:+  +#+ +#++:++#   %)
	$(info %   +#+   +#+# +#+     +#+ +#+       +#+ +#+        %)
	$(info %   #+#    #+# #+#     #+# #+#       #+# #+#        %)
	$(info %    ########  ###     ### ###       ### ########## %)
	$(info %                                                   %)
	$(info %                ::::::::  ::::::::::               %)
	$(info %               :+:    :+: :+:                      %)
	$(info %               +:+    +:+ +:+                      %)
	$(info %               +#+    +:+ :#::+::#                 %)
	$(info %               +#+    +#+ +#+                      %)
	$(info %               #+#    #+# #+#                      %)
	$(info %                ########  ###                      %)
	$(info %                                                   %)
	$(info %    :::        ::::::::::: :::::::::: ::::::::::   %)
	$(info %    :+:            :+:     :+:        :+:          %)
	$(info %    +:+            +:+     +:+        +:+          %)
	$(info %    +#+            +#+     :#::+::#   +#++:++#     %)
	$(info %    +#+            +#+     +#+        +#+          %)
	$(info %    #+#            #+#     #+#        #+#          %)
	$(info %    ########## ########### ###        ##########   %)
	$(info %%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%)
	$(info %%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%)
	$(info )
	$(info )

gameDyn-debug: gameDyn.c
	gcc  -o $@ $^  $(LDFLAGS) $(CFLAGS) -pg


gameDyn: gameDyn.c
	gcc  -o $@ $^  $(LDFLAGS) $(CFLAGS)

clean:
	rm -f game gameDyn
