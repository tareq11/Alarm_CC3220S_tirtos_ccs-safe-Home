# invoke SourceDir generated makefile for release.pem4
release.pem4: .libraries,release.pem4
.libraries,release.pem4: package/cfg/release_pem4.xdl
	$(MAKE) -f D:\Documents\ww\Lab_9_ADC-GPIO_SAMPLE_CC3220S_tirtos_ccs/src/makefile.libs

clean::
	$(MAKE) -f D:\Documents\ww\Lab_9_ADC-GPIO_SAMPLE_CC3220S_tirtos_ccs/src/makefile.libs clean

