#Makefile made by Coder 1 
CC = gcc
CFLAGS = -Wall -I/usr/include/ -I.
LDFLAGS = -lncurses 

all: printLogo main
	
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
main: main.c game.c
	gcc  -o $@ $^  $(LDFLAGS) $(CFLAGS)

main-debug: main.c game.c
	gcc  -o $@ $^  $(LDFLAGS) $(CFLAGS) -pg

clean:
	rm -f main game
