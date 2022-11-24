FROM gitpod/workspace-full-vnc

RUN \
	# Update and upgrade installation (APT)
	sudo apt update \
	&& sudo apt upgrade -y \
	# Install useful programs (APT)
	&& sudo apt install -y \
		libgl-dev \
		libgtk-4-dev \
		libgtkmm-4.0-dev \
		python3 \
	# IDK
	&& sudo apt clean && sudo rm -rf /var/cache/apt/* && sudo rm -rf /var/lib/apt/lists/* && sudo rm -rf /tmp/* \
	# Install useful programs (PIP)
	&& sudo pip install --upgrade \
		conan \
		cmake
