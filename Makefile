include etc/Configuration.GNUMakefile

export ALPHAOS_BASE=${shell pwd}

VERSION=0.0.1

all: source link

source:
	@make --no-print-directory -C src/ CONF_FILE=${shell pwd}/etc/Configuration.GNUMakefile

link:
	@echo "Linking . . . "
	@ld ${LD_FLAGS}

clean:
	@make -C src/ -f ${ALPHAOS_BASE}/etc/Clean.GNUMakefile
	@make -f ${ALPHAOS_BASE}/etc/Clean.GNUMakefile
zip:
	@./bin/7z/7z a AlphaOS_${VERSION}.7z -r ./*
	


