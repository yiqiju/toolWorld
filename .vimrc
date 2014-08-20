set ruler
set hlsearch
set et sts=3 sw=3
set ai
set backspace=indent,eol,start
set number
autocmd FileType h,c,cpp set colorcolumn=81
set bg=dark
set guifont=Monaco\ 12

syntax enable 
set nu
set nocompatible               " be iMproved
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
" smooth scroll
set scroll=5
" spell check
" set spell spelllang=en_us

" Remove trailing white space
autocmd FileType h,c,cpp autocmd BufWritePre <buffer> :%s/\s\+$//e
autocmd BufNewFile,BufRead *.sel set ft=javascript
autocmd BufNewFile,BufRead *.inc set ft=javascript

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

" let g:kolor_italic=1
" let g:kolor_bold=1
" let g:kolor_underlined=0
" let g:kolor_alternative_matchparen=0
