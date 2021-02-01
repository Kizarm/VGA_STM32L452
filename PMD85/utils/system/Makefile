all:
	cd booter && $(MAKE) all
	mv booter/loader32.rmm ./booter2-pmd85-pmd32.rmm
	cd basic  && $(MAKE) all
	mv basic/basic2A.rmm .
	cd monit  && $(MAKE) all
	mv monit/monit2A.rom .

clean:
	cd booter && $(MAKE) clean
	cd basic  && $(MAKE) clean
	cd monit  && $(MAKE) clean
.PHONY: all clean

