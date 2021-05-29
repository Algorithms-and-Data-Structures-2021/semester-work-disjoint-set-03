import argparse
from random import randint
from pathlib import Path

DEFAULT_DESCRIPTION = 'CSV dataset generator for Join'
DEFAULT_SAMPLES = 100
DEFAULT_DATASETS = 1


def parse_args():
    parser = argparse.ArgumentParser(description=DEFAULT_DESCRIPTION)

    parser.add_argument('--datasets',
                        type=int,
                        default=DEFAULT_DATASETS,
                        help='number of datasets to generate (default: {})'.format(DEFAULT_DATASETS))

    parser.add_argument('--samples',
                        type=int,
                        default=DEFAULT_SAMPLES,
                        help='number of samples to generate (default: {})'.format(DEFAULT_SAMPLES))

    return parser.parse_args()


if __name__ == '__main__':
    args = parse_args()
    output = f'data/join/00/{args.samples}.csv'

    # валидация аргументов
    if args.datasets < 0 or args.datasets > 10:
        raise ValueError('Number of datasets must be greater than 0 and not greater than 10.')

    if args.samples < 0 or args.samples > 5000000:
        raise ValueError('Number of samples must be greater than 0 and not greater than 5000000.')

    # запись данных в файл
    for dataset in range(args.datasets):
        if dataset != 9:
            output = output.replace(f'0{dataset}', f'0{dataset + 1}', 1)
        else:
            output = output.replace(f'0{dataset}', '10', 1)

        if dataset != 9:
            Path(f"data/join/0{dataset + 1}").mkdir(parents=True, exist_ok=True)
        else:
            Path("data/join/10").mkdir(parents=True, exist_ok=True)

        with open(output, 'w+') as file:
            for i in range(args.samples - 1):
                file.write('{}, {}\n'.format(randint(0, args.samples), randint(0, args.samples)))
            file.write('{}, {}'.format(randint(0, args.samples), randint(0, args.samples)))
