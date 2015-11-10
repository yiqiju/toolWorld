set ruler
set hlsearch
set et sts=3 sw=3
" PEP 8 requires 4 spaces
autocmd FileType python set et sts=4 sw=4
set ai
set backspace=indent,eol,start
set number
autocmd FileType h,c,cpp,sql,javascript,python set colorcolumn=81
autocmd BufNewFile,BufRead *.m4 set colorcolumn=81
set bg=dark

syntax enable 
set nocompatible " be iMproved
set autochdir
set backspace=indent,eol,start
set foldenable
set hidden
set incsearch
set laststatus=2
set tags=./tegs,tags;/
set wildmenu
set clipboard+=unnamed
set switchbuf=useopen,usetab
set tags=./tegs,tags;/
set scroll=5 " smooth scroll

" set spell spelllang=en_us " spell check

" Remove trailing white space
"autocmd FileType h,c,cpp,m4,javascript,py autocmd BufWritePre <buffer> :%s/\s\+$//e
"autocmd BufNewFile,BufRead *.m4 autocmd BufWritePre <buffer> :%s/\s\+$//e
" Map file format, so that we get highlight
"autocmd BufNewFile,BufRead *.sel set ft=javascript
autocmd BufNewFile,BufRead *.inc set ft=javascript
autocmd BufNewFile,BufRead *.m4  set ft=sql

" Note trailing space for other files that were not taken care of by the auto remove
set listchars=tab:>-,trail:$
set list

"" Set up colorscheme
colorscheme default
highlight Cursor ctermfg=Yellow ctermbg=Yellow 

"" Set up completion menu
highlight Pmenu      ctermfg=Gray    ctermbg=DarkBlue  guifg=Cyan guibg=DarkBlue 
highlight PmenuSel   ctermfg=White   ctermbg=DarkGreen cterm=Bold guifg=White guibg=DarkBlue gui=Bold 
highlight PmenuSbar  ctermfg=White   ctermbg=DarkGreen            guibg=Cyan 
highlight PmenuThumb ctermfg=Black   ctermbg=DarkGreen            guifg=White
highlight SpellBad   ctermfg=White   ctermbg=Red       cterm=Underline

if has('gui_running')
      colorscheme solarized
      set guifont=Monaco\ 10
end

"" Change to hard tab when kernel code
"set noet sts=8 sw=8
