FROM gitpod/workspace-full-vnc

RUN \
	# Update and upgrade installation (APT)
	sudo apt-get update \
	&& sudo apt-get upgrade -y \
	# Install useful programs (APT)
	&& sudo apt-get install -y \
		libgl-dev \
		libgtk-3-dev \
		libgtkmm-3.0-dev \
		python3 \
	# IDK
	&& sudo apt-get clean && sudo rm -rf /var/cache/apt/* && sudo rm -rf /var/lib/apt/lists/* && sudo rm -rf /tmp/* \
	# Install useful programs (PIP)
	&& sudo pip install --upgrade \
		conan \
		cmake
