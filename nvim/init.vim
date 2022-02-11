call plug#begin('~/.vim/plugged')

" Make sure you use single quotes
Plug 'dracula/vim', { 'as': 'dracula' }
Plug 'jiangmiao/auto-pairs'
Plug 'rust-lang/rust.vim'
Plug 'pangloss/vim-javascript'

" Use release branch (recommend)
Plug 'neoclide/coc.nvim', {'branch': 'release'}

" On-demand loading
Plug 'scrooloose/nerdtree', { 'on':  'NERDTreeToggle' }

" Using git URL
Plug 'https://github.com/junegunn/vim-github-dashboard.git'

" Plugin options
Plug 'nsf/gocode', { 'tag': 'v.20150303', 'rtp': 'vim' }

" Plugin outside ~/.vim/plugged with post-update hook
Plug 'junegunn/fzf', { 'dir': '~/.fzf', 'do': 'yes \| ./install' }

call plug#end()

syntax enable
filetype plugin indent on

colorscheme dracula
autocmd VimEnter * wincmd p
autocmd VimEnter * set number
autocmd VimEnter * highlight NonText ctermbg=none
autocmd VimEnter * highlight Normal ctermbg=none

" Tab and indentation
set tabstop=3
set shiftwidth=3
set expandtab
set smartindent
