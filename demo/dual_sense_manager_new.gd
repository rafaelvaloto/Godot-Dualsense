extends DualSenseManager

func device_connected(device_id: int):
	print("Sucesso! Controle detectado com ID: ", device_id)
	test_lightbar()
	test_weapon()
	test_rumble()

func device_disconnected(device_id: int):
	print("Controle desconectado: ", device_id)
