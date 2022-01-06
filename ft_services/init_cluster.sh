#!/bin/bash

# 42brew
mkdir $HOME/.brew && curl -fsSL https://github.com/Homebrew/brew/tarball/master | tar xz --strip 1 -C $HOME/.brew
mkdir -p /tmp/.$(whoami)-brew-locks
mkdir -p $HOME/.brew/var/homebrew
ln -s /tmp/.$(whoami)-brew-locks $HOME/.brew/var/homebrew/locks
export PATH="$HOME/.brew/bin:$PATH"
brew update && brew upgrade

curl -fLo ~/.vim/autoload/plug.vim --create-dirs \
https://raw.githubusercontent.com/junegunn/vim-plug/master/plug.vim

cp zsh ~/.zshrc
cp vim ~/.vimrc
source ~/.zshrc

echo "open vim :PlugInstall"

git config --global user.name from97
git config --global user.email skm1104@daum.net

brew install minikube

cd ~
git clone https://github.com/alexandregv/42toolbox
