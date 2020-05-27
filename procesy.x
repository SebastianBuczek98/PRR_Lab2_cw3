struct message{
	char value[64];
};

program LAB2_PROGR{
	version LAB2_VERS{
		void getMsg(message)=1;
	}=1;
}=0x23451111;
